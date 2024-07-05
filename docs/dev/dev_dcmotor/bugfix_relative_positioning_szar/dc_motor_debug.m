clc, clear variables
%%

filename = 'putty_version_pmich.log';
filename1 = 'putty_version_szar.log';
logTable = readtable(filename);
logTable1 = readtable(filename1);


logArray = table2array(logTable);
logArray1 = table2array(logTable1);

Ts = logArray(:,1) * 10e6;


figure(1)
plot(Ts, logArray(:,2), 'r');
grid on
hold on
plot(Ts, logArray(:,3), 'g');
plot(Ts, logArray1(:,2), 'b');
plot(Ts, logArray1(:,3), 'm');

legend('getRotation pimich','getTargetRotation pimich','getRotation szar', 'getTartgetRotation szar')