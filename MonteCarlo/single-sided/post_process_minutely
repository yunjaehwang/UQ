%%
targetDate = datetime(2019,2,11,12,0,0);
timeIdx.CT = (targetDate-hours(36)) <= minutely.CT.time & minutely.CT.time <= targetDate ; 
timeIdx.NE = (targetDate-hours(36)) <= minutely.NE.time & minutely.NE.time <= targetDate ; 
timeIdx.NW = (targetDate-hours(36)) <= minutely.NW.time & minutely.NW.time <= targetDate ; 
timeIdx.SE = (targetDate-hours(36)) <= minutely.SE.time & minutely.SE.time <= targetDate ; 
timeIdx.SW = (targetDate-hours(36)) <= minutely.SW.time & minutely.SW.time <= targetDate ; 

time_ref = targetDate-hours(36):minutes(1):targetDate;
time_in_hr = (0:2160)/60;

TEMP.CT.top.mean = interp1(minutely.CT.time(timeIdx.CT), minutely.CT.top.mean(timeIdx.CT), time_ref);
TEMP.NE.top.mean = interp1(minutely.NE.time(timeIdx.NE), minutely.NE.top.mean(timeIdx.NE), time_ref);
TEMP.NW.top.mean = interp1(minutely.NW.time(timeIdx.NW), minutely.NW.top.mean(timeIdx.NW), time_ref);
TEMP.SE.top.mean = interp1(minutely.SE.time(timeIdx.SE), minutely.SE.top.mean(timeIdx.SE), time_ref);
TEMP.SW.top.mean = interp1(minutely.SW.time(timeIdx.SW), minutely.SW.top.mean(timeIdx.SW), time_ref);

TEMP.CT.mid.mean = interp1(minutely.CT.time(timeIdx.CT), minutely.CT.mid.mean(timeIdx.CT), time_ref);
TEMP.NE.mid.mean = interp1(minutely.NE.time(timeIdx.NE), minutely.NE.mid.mean(timeIdx.NE), time_ref);
TEMP.NW.mid.mean = interp1(minutely.NW.time(timeIdx.NW), minutely.NW.mid.mean(timeIdx.NW), time_ref);
TEMP.SE.mid.mean = interp1(minutely.SE.time(timeIdx.SE), minutely.SE.mid.mean(timeIdx.SE), time_ref);
TEMP.SW.mid.mean = interp1(minutely.SW.time(timeIdx.SW), minutely.SW.mid.mean(timeIdx.SW), time_ref);

TEMP.CT.low.mean = interp1(minutely.CT.time(timeIdx.CT), minutely.CT.low.mean(timeIdx.CT), time_ref);
TEMP.NE.low.mean = interp1(minutely.NE.time(timeIdx.NE), minutely.NE.low.mean(timeIdx.NE), time_ref);
TEMP.NW.low.mean = interp1(minutely.NW.time(timeIdx.NW), minutely.NW.low.mean(timeIdx.NW), time_ref);
TEMP.SE.low.mean = interp1(minutely.SE.time(timeIdx.SE), minutely.SE.low.mean(timeIdx.SE), time_ref);
TEMP.SW.low.mean = interp1(minutely.SW.time(timeIdx.SW), minutely.SW.low.mean(timeIdx.SW), time_ref);

TEMP.CT.top.std = interp1(minutely.CT.time(timeIdx.CT), minutely.CT.top.std(timeIdx.CT), time_ref);
TEMP.NE.top.std = interp1(minutely.NE.time(timeIdx.NE), minutely.NE.top.std(timeIdx.NE), time_ref);
TEMP.NW.top.std = interp1(minutely.NW.time(timeIdx.NW), minutely.NW.top.std(timeIdx.NW), time_ref);
TEMP.SE.top.std = interp1(minutely.SE.time(timeIdx.SE), minutely.SE.top.std(timeIdx.SE), time_ref);
TEMP.SW.top.std = interp1(minutely.SW.time(timeIdx.SW), minutely.SW.top.std(timeIdx.SW), time_ref);

TEMP.CT.mid.std = interp1(minutely.CT.time(timeIdx.CT), minutely.CT.mid.std(timeIdx.CT), time_ref);
TEMP.NE.mid.std = interp1(minutely.NE.time(timeIdx.NE), minutely.NE.mid.std(timeIdx.NE), time_ref);
TEMP.NW.mid.std = interp1(minutely.NW.time(timeIdx.NW), minutely.NW.mid.std(timeIdx.NW), time_ref);
TEMP.SE.mid.std = interp1(minutely.SE.time(timeIdx.SE), minutely.SE.mid.std(timeIdx.SE), time_ref);
TEMP.SW.mid.std = interp1(minutely.SW.time(timeIdx.SW), minutely.SW.mid.std(timeIdx.SW), time_ref);

TEMP.CT.low.std = interp1(minutely.CT.time(timeIdx.CT), minutely.CT.low.std(timeIdx.CT), time_ref);
TEMP.NE.low.std = interp1(minutely.NE.time(timeIdx.NE), minutely.NE.low.std(timeIdx.NE), time_ref);
TEMP.NW.low.std = interp1(minutely.NW.time(timeIdx.NW), minutely.NW.low.std(timeIdx.NW), time_ref);
TEMP.SE.low.std = interp1(minutely.SE.time(timeIdx.SE), minutely.SE.low.std(timeIdx.SE), time_ref);
TEMP.SW.low.std = interp1(minutely.SW.time(timeIdx.SW), minutely.SW.low.std(timeIdx.SW), time_ref);


figure();
subplot(1,2,1);
hold on
% measurement
plot(time_in_hr, TEMP.CT.top.mean, 'b'); 
plot(time_in_hr, TEMP.NE.top.mean, 'b'); 
plot(time_in_hr, TEMP.NW.top.mean, 'b'); 
plot(time_in_hr, TEMP.SE.top.mean, 'b'); 
plot(time_in_hr, TEMP.SW.top.mean, 'b'); 

plot(time_in_hr, TEMP.CT.mid.mean, 'k'); 
plot(time_in_hr, TEMP.NE.mid.mean, 'k'); 
plot(time_in_hr, TEMP.NW.mid.mean, 'k'); 
plot(time_in_hr, TEMP.SE.mid.mean, 'k'); 
plot(time_in_hr, TEMP.SW.mid.mean, 'k'); 

plot(time_in_hr, TEMP.CT.low.mean, 'r');
plot(time_in_hr, TEMP.NE.low.mean, 'r');
plot(time_in_hr, TEMP.NW.low.mean, 'r');
plot(time_in_hr, TEMP.SE.low.mean, 'r');
plot(time_in_hr, TEMP.SW.low.mean, 'r');

xlim([12 36]);
xlabel('Time [hr]');
ylabel('Temperature [C]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});

tempIndoor.mean =  mean([TEMP.CT.top.mean; TEMP.NE.top.mean; TEMP.NW.top.mean;...
    TEMP.SE.top.mean; TEMP.SW.top.mean; TEMP.CT.mid.mean; ...
    TEMP.NE.mid.mean; TEMP.NW.mid.mean; TEMP.SE.mid.mean; ...
    TEMP.SW.mid.mean; TEMP.CT.low.mean; TEMP.NE.low.mean; ...
    TEMP.NW.low.mean; TEMP.SE.low.mean; TEMP.SW.low.mean])';

tempIndoor.std = sqrt((...
    TEMP.CT.top.std.^2 + (TEMP.CT.top.mean-tempIndoor.mean').^2 + ...
    TEMP.CT.mid.std.^2 + (TEMP.CT.mid.mean-tempIndoor.mean').^2 + ...
    TEMP.CT.low.std.^2 + (TEMP.CT.low.mean-tempIndoor.mean').^2 + ...
    TEMP.SE.top.std.^2 + (TEMP.SE.top.mean-tempIndoor.mean').^2 + ...
    TEMP.SE.mid.std.^2 + (TEMP.SE.mid.mean-tempIndoor.mean').^2 + ...
    TEMP.SE.low.std.^2 + (TEMP.SE.low.mean-tempIndoor.mean').^2 + ...
    TEMP.NE.top.std.^2 + (TEMP.NE.top.mean-tempIndoor.mean').^2 + ...
    TEMP.NE.mid.std.^2 + (TEMP.NE.mid.mean-tempIndoor.mean').^2 + ...
    TEMP.NE.low.std.^2 + (TEMP.NE.low.mean-tempIndoor.mean').^2 + ...
    TEMP.SW.top.std.^2 + (TEMP.SW.top.mean-tempIndoor.mean').^2 + ...
    TEMP.SW.mid.std.^2 + (TEMP.SW.mid.mean-tempIndoor.mean').^2 + ...
    TEMP.SW.low.std.^2 + (TEMP.SW.low.mean-tempIndoor.mean').^2 + ...
    TEMP.NW.top.std.^2 + (TEMP.NW.top.mean-tempIndoor.mean').^2 + ...
    TEMP.NW.mid.std.^2 + (TEMP.NW.mid.mean-tempIndoor.mean').^2 + ...
    TEMP.NW.low.std.^2 + (TEMP.NW.low.mean-tempIndoor.mean').^2)/15)';
  

  
%%    

subplot(1,2,2); hold on
plot(time_in_hr, tempIndoor.mean, 'b', 'linewidth',2);
plot(t_stamp, mean(data.temp_in)-273.15,'k','linewidth',2);

patch([time_in_hr, fliplr(time_in_hr)], [tempIndoor.mean'+tempIndoor.std',  fliplr(tempIndoor.mean'-tempIndoor.std')],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
plot(time_in_hr, tempIndoor.mean, 'b', 'linewidth',2);
xlim([12 36]);
ylim([16 30]);

% prediction
% patch([t_stamp' fliplr(t_stamp')], [max(data.temp_out) fliplr(min(data.temp_out))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
patch([t_stamp' fliplr(t_stamp')], [max(data.temp_in) fliplr(min(data.temp_in))]-273.15,[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.temp_out)-273.15,'k','linewidth',2);
plot(t_stamp, mean(data.temp_in)-273.15,'k','linewidth',2);

legend('Measurement; mean + 1 std','Prediction; min&max');
xlim([12 36]);
xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});