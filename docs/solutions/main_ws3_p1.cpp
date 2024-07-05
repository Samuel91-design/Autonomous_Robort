#include "mbed.h"

// pes board pin map
#include "pm2_drivers/PESBoardPinMap.h"

// drivers
#include "pm2_drivers/DebounceIn.h"
#include "pm2_drivers/FastPWM/FastPWM.h"
#include "pm2_drivers/DCMotor.h"

bool do_execute_main_task = false; // this variable will be toggled via the user button (blue button) and
                                   // decides whether to execute the main task or not
bool do_reset_all_once = false;    // this variable is used to reset certain variables and objects and
                                   // shows how you can run a code segment only once

// objects for user button (blue button) handling on nucleo board
DebounceIn user_button(USER_BUTTON); // create DebounceIn object to evaluate the user button
                                     // falling and rising edge
void toggle_do_execute_main_fcn();   // custom function which is getting executed when user
                                     // button gets pressed, definition below

// main runs as an own thread
int main()
{
    // attach button fall function address to user button object, button has a pull-up resistor
    user_button.fall(&toggle_do_execute_main_fcn);

    // while loop gets executed every main_task_period_ms milliseconds, this is a
    // simple approach to repeatedly execute main
    const int main_task_period_ms = 20; // define main task period time in ms e.g. 20 ms, there for
                                        // the main task will run 50 times per second
    Timer main_task_timer;              // create Timer object which we use to run the main task
                                        // every main_task_period_ms

    // led on nucleo board
    DigitalOut user_led(USER_LED);

    // additional led
    // create DigitalOut object to command extra led, you need to add an aditional resistor, e.g. 220...500 Ohm
    // a led has an anode (+) and a cathode (-), the cathode needs to be connected to ground via a resistor
    DigitalOut led1(PB_9);

    // create object to enable power electronics for the dc motors
    DigitalOut enable_motors(PB_ENABLE_DCMOTORS);

    // // motor M1
    // FastPWM pwm_M1(PB_PWM_M1); // create FastPWM object to command motor M1

    const float voltage_max = 12.0f; // maximum voltage of battery packs, adjust this to
                                     // 6.0f V if you only use one battery pack

    // // motor M2
    // const float gear_ratio_M2 = 78.125f; // gear ratio
    // const float kn_M2 = 180.0f / 12.0f;  // motor constant [rpm/V]
    // // it is assumed that only one motor is available, there fore
    // // we use the pins from M1, so you can leave it connected to M1
    // DCMotor motor_M2(PB_PWM_M1, PB_ENC_A_M1, PB_ENC_B_M1, gear_ratio_M2, kn_M2, voltage_max);
    // // limit max. velocity to half physical possible velocity
    // motor_M2.setMaxVelocity(motor_M2.getMaxPhysicalVelocity() * 0.5f);
    // // enable the motion planner for smooth movements
    // motor_M2.enableMotionPlanner(true);
    // // limit max. acceleration to half of the default acceleration
    // motor_M2.setMaxAcceleration(motor_M2.getMaxAcceleration() * 0.5f);

    // motor M3
    const float gear_ratio_M3 = 78.125f; // gear ratio
    const float kn_M3 = 180.0f / 12.0f;  // motor constant [rpm/V]
    // it is assumed that only one motor is available, there fore
    // we use the pins from M1, so you can leave it connected to M1
    DCMotor motor_M3(PB_PWM_M1, PB_ENC_A_M1, PB_ENC_B_M1, gear_ratio_M3, kn_M3, voltage_max);
    // enable the motion planner for smooth movement
    motor_M3.enableMotionPlanner(true);
    // limit max. velocity to half physical possible velocity
    motor_M3.setMaxVelocity(motor_M3.getMaxPhysicalVelocity() * 0.5f);

    // start timer
    main_task_timer.start();

    // this loop will run forever
    while (true) {
        main_task_timer.reset();

        if (do_execute_main_task) {

            // visual feedback that the main task is executed, setting this once would actually be enough
            led1 = 1;

            // enable hardwaredriver dc motors: 0 -> disabled, 1 -> enabled
            enable_motors = 1; // setting this once would actually be enough

            // pwm_M1.write(0.75f); // apply 6V to the motor
            // motor_M2.setVelocity(motor_M2.getMaxVelocity());
            motor_M3.setRotation(3.0f);
        } else {
            // the following code block gets executed only once
            if (do_reset_all_once) {
                do_reset_all_once = false;

                // reset variables and objects
                led1 = 0;
            }
        }

        // toggling the user led
        user_led = !user_led;

        // read timer and make the main thread sleep for the remaining time span (non blocking)
        int main_task_elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(main_task_timer.elapsed_time()).count();
        thread_sleep_for(main_task_period_ms - main_task_elapsed_time_ms);
    }
}

void toggle_do_execute_main_fcn()
{
    // toggle do_execute_main_task if the button was pressed
    do_execute_main_task = !do_execute_main_task;
    // set do_reset_all_once to true if do_execute_main_task changed from false to true
    if (do_execute_main_task)
        do_reset_all_once = true;
}