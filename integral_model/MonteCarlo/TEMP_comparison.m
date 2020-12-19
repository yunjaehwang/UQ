clear;
clc;

% case: 
% targetDate = datetime(2019,2,6,12,0,0);    ii=1; % wv
% targetDate = datetime(2019,2,3,12,0,0);    ii=2; % sv 0202
% % targetDate = datetime(2019,2,3,12,0,0);    % sv 0203
targetDate = datetime(2019,2,12,12,0,0);    ii=3; % sw
% targetDate = datetime(2019,2,09,12,0,0);    ii=4;% sfv

% load timestamp
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/time_stamp4.mat');

% load measurement data
load('/home/yunjaeh/github/Bangladesh_measurement/TemperatureWind/Data/MeasurementDataTable.mat');

% load single-sided ventilation prediction data
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/data_v6.temp/sw/data_summary.mat');
singleData = data;

% load cross-ventilation prediction data
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/data_v6.temp/sw/data_summary.mat');
crossData = data;

%%%%% values for calculation
vol_house = 17.72;
% ach_in = 4.75;
ach = data.vent_rate*3600/vol_house;


%% compute prediction mean and standard deviation
%%% time average, span = 30 min
dt = 0.5;
t_averaged = 0:dt:(27-dt);
ci = 0.025;

for i= 1:length(t_averaged)
% for i = 1
    idx = t_averaged(i) < t_stamp & t_stamp < (t_averaged(i)+dt);
    [f,x] = ecdf(reshape(singleData.temp_in(:,idx)-273.15,1,[]));
    T_indoor.mean(i) = mean(reshape(singleData.temp_in(:,idx),1,[]))-273.15;
    T_indoor.ci_min(i) = max( x(f < ci) );
    T_indoor.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(singleData.wall_in(:,idx)-273.15,1,[]));
    T_wall_in.mean(i) = mean(reshape(singleData.wall_in(:,idx),1,[]))-273.15;
    T_wall_in.ci_min(i) = max( x(f < ci) );
    T_wall_in.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(singleData.wall_out(:,idx)-273.15,1,[]));
    T_wall_out.mean(i) = mean(reshape(singleData.wall_out(:,idx),1,[]))-273.15;
    T_wall_out.ci_min(i) = max( x(f < ci) );
    T_wall_out.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(singleData.roof_in(:,idx)-273.15,1,[]));
    T_roof_in.mean(i) = mean(reshape(singleData.roof_in(:,idx),1,[]))-273.15;
    T_roof_in.ci_min(i) = max( x(f < ci) );
    T_roof_in.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(singleData.roof_out(:,idx)-273.15,1,[]));
    T_roof_out.mean(i) = mean(reshape(singleData.roof_out(:,idx),1,[]))-273.15;
    T_roof_out.ci_min(i) = max( x(f < ci) );
    T_roof_out.ci_max(i) = min( x(f > (1-ci) ) );
end
single.T_indoor= T_indoor;
single.T_wall_in = T_wall_in;
single.T_wall_out = T_wall_out;
single.T_roof_in = T_roof_in;
single.T_roof_out = T_roof_out;


for i= 1:length(t_averaged)
% for i = 1
    idx = t_averaged(i) < t_stamp & t_stamp < (t_averaged(i)+dt);
    [f,x] = ecdf(reshape(crossData.temp_in(:,idx)-273.15,1,[]));
    T_indoor.mean(i) = mean(reshape(crossData.temp_in(:,idx),1,[]))-273.15;
    T_indoor.ci_min(i) = max( x(f < ci) );
    T_indoor.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(crossData.wall_in(:,idx)-273.15,1,[]));
    T_wall_in.mean(i) = mean(reshape(crossData.wall_in(:,idx),1,[]))-273.15;
    T_wall_in.ci_min(i) = max( x(f < ci) );
    T_wall_in.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(crossData.wall_out(:,idx)-273.15,1,[]));
    T_wall_out.mean(i) = mean(reshape(crossData.wall_out(:,idx),1,[]))-273.15;
    T_wall_out.ci_min(i) = max( x(f < ci) );
    T_wall_out.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(crossData.roof_in(:,idx)-273.15,1,[]));
    T_roof_in.mean(i) = mean(reshape(crossData.roof_in(:,idx),1,[]))-273.15;
    T_roof_in.ci_min(i) = max( x(f < ci) );
    T_roof_in.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(crossData.roof_out(:,idx)-273.15,1,[]));
    T_roof_out.mean(i) = mean(reshape(crossData.roof_out(:,idx),1,[]))-273.15;
    T_roof_out.ci_min(i) = max( x(f < ci) );
    T_roof_out.ci_max(i) = min( x(f > (1-ci) ) );
end
cross.T_indoor= T_indoor;
cross.T_wall_in = T_wall_in;
cross.T_wall_out = T_wall_out;
cross.T_roof_in = T_roof_in;
cross.T_roof_out = T_roof_out;

%%

save('temp_sw.mat','single','cross','ii','targetDate')

%% compute measurement and standard deviation
dt = 0.5;
t_averaged = 0:dt:(27-dt);

% indoor air temperature
timeIdx = (targetDate-hours(27)) <= hourly.Time & hourly.Time <= targetDate ; 
 
% figure();
% subplot(1,2,1);
% hold on
% % measurement
% plot(0:27, hourly.mean.CT_low(timeIdx), 'b'); 
% plot(0:27, hourly.mean.NE_low(timeIdx), 'b'); 
% plot(0:27, hourly.mean.NW_low(timeIdx), 'b'); 
% plot(0:27, hourly.mean.SE_low(timeIdx), 'b'); 
% plot(0:27, hourly.mean.SW_low(timeIdx), 'b'); 
% 
% plot(0:27, hourly.mean.CT_mid(timeIdx), 'k'); 
% plot(0:27, hourly.mean.NE_mid(timeIdx), 'k'); 
% plot(0:27, hourly.mean.NW_mid(timeIdx), 'k'); 
% % plot(0:27, hourly.mean.SE_mid(timeIdx), 'k'); 
% plot(0:27, hourly.mean.SW_mid(timeIdx), 'k'); 
% 
% plot(0:27, hourly.mean.CT_top(timeIdx), 'r'); 
% plot(0:27, hourly.mean.NE_top(timeIdx), 'r'); 
% plot(0:27, hourly.mean.NW_top(timeIdx), 'r'); 
% plot(0:27, hourly.mean.SE_top(timeIdx), 'r'); 
% plot(0:27, hourly.mean.SW_top(timeIdx), 'r'); 
% 
% % xlim([12 36]);
% xlabel('Time [hr]');
% ylabel('Temperature [C]');
% xticks([3:12:27 ]);
% xticklabels({'Noon','Midnight','Noon'});



tempIndoor.mean = mean([hourly.mean.CT_low(timeIdx) ,hourly.mean.CT_mid(timeIdx) ,hourly.mean.CT_top(timeIdx), ...
    hourly.mean.NE_low(timeIdx) ,hourly.mean.NE_mid(timeIdx) ,hourly.mean.NE_top(timeIdx), ...
    hourly.mean.NW_low(timeIdx), hourly.mean.NW_mid(timeIdx), hourly.mean.NW_top(timeIdx), ...
    hourly.mean.SE_low(timeIdx), hourly.mean.SE_mid(timeIdx), hourly.mean.SE_top(timeIdx), ...
    hourly.mean.SW_low(timeIdx) ,hourly.mean.SW_mid(timeIdx), hourly.mean.SW_top(timeIdx)]');


tempIndoor.std = sqrt((...
    hourly.std.CT_top(timeIdx).^2 + (hourly.mean.CT_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.CT_mid(timeIdx).^2 + (hourly.mean.CT_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.CT_low(timeIdx).^2 + (hourly.mean.CT_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SE_top(timeIdx).^2 + (hourly.mean.SE_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SE_mid(timeIdx).^2 + (hourly.mean.SE_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SE_low(timeIdx).^2 + (hourly.mean.SE_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NE_top(timeIdx).^2 + (hourly.mean.NE_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NE_mid(timeIdx).^2 + (hourly.mean.NE_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NE_low(timeIdx).^2 + (hourly.mean.NE_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SW_top(timeIdx).^2 + (hourly.mean.SW_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SW_mid(timeIdx).^2 + (hourly.mean.SW_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.SW_low(timeIdx).^2 + (hourly.mean.SW_low(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NW_top(timeIdx).^2 + (hourly.mean.NW_top(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NW_mid(timeIdx).^2 + (hourly.mean.NW_mid(timeIdx)-tempIndoor.mean').^2 + ...
    hourly.std.NW_low(timeIdx).^2 + (hourly.mean.NW_low(timeIdx)-tempIndoor.mean').^2)/15)';
    
   

% indoor air temperature comparison
% figure();
subplot(4,2,2*(ii-1)+1);
hold on

plot(t_averaged+dt/2, cross.T_indoor.mean, 'r', 'linewidth',2);
patch([0.5:27.5, fliplr(0.5:27.5)], [tempIndoor.mean+tempIndoor.std,  fliplr(tempIndoor.mean-tempIndoor.std)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [cross.T_indoor.ci_max,  fliplr(cross.T_indoor.ci_min)],[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);

plot(0.5:27.5, tempIndoor.mean, 'k', 'linewidth',2);
plot(t_averaged+dt/2, cross.T_indoor.mean, 'r', 'linewidth',2);

xlabel('Time');
ylabel('Temperature [^\circC]');
xlim([3 27]);
xticks([3 15 27]);
xticklabels({'Noon','Midnight','Noon'});

ylim([16 32]);
yticks([16 24 32]);

%%% hourly data


subplot(4,2,2*(ii-1)+2);
hold on


patch([0.5:27.5, fliplr(0.5:27.5)], [tempIndoor.mean+tempIndoor.std,  fliplr(tempIndoor.mean-tempIndoor.std)],[0.8 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [single.T_indoor.ci_max,  fliplr(single.T_indoor.ci_min)],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, tempIndoor.mean, 'k', 'linewidth',2);
plot(t_averaged+dt/2, single.T_indoor.mean, 'b', 'linewidth',2);
% plot(t_averaged+dt/2, cross.T_indoor.mean, 'r', 'linewidth',2);


% legend('Measurement','Prediction: single-sided ventilation', 'Prediction: cross ventilation');



xlabel('Time');
ylabel('Temperature [^\circC]');
xlim([3 27]);
xticks([3 15 27]);
xticklabels({'Noon','Midnight','Noon'});

ylim([16 32]);
yticks([16 24 32]);



%% wall, roof surface temperatures




%%
% wall surface temperatures

timeIdx = (targetDate-hours(27)) <= hourly.Time & hourly.Time <= targetDate ; 
 
figure();
subplot(2,2,1); hold on
% measurement
patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.N_wall_in(timeIdx)'+hourly.std.N_wall_in(timeIdx)',...
    fliplr(hourly.mean.N_wall_in(timeIdx)'-hourly.std.N_wall_in(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.N_wall_in(timeIdx), 'k');  

patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.S_wall_in(timeIdx)'+hourly.std.S_wall_in(timeIdx)',...
    fliplr(hourly.mean.S_wall_in(timeIdx)'-hourly.std.S_wall_in(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.S_wall_in(timeIdx), 'k');  

patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.E_wall_in(timeIdx)'+hourly.std.E_wall_in(timeIdx)',...
    fliplr(hourly.mean.E_wall_in(timeIdx)'-hourly.std.E_wall_in(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',.5);
plot(0.5:27.5, hourly.mean.E_wall_in(timeIdx), 'k');  

patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.W_wall_in(timeIdx)'+hourly.std.W_wall_in(timeIdx)',...
    fliplr(hourly.mean.W_wall_in(timeIdx)'-hourly.std.W_wall_in(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.W_wall_in(timeIdx), 'k');  


% prediction
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [cross.T_wall_in.ci_max,  fliplr(cross.T_wall_in.ci_min)],[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, cross.T_wall_in.mean, 'r', 'linewidth',2);

patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [single.T_wall_in.ci_max,  fliplr(single.T_wall_in.ci_min)],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, single.T_wall_in.mean, 'b', 'linewidth',2);

%%% output result
% patch([t_stamp' fliplr(t_stamp')], [max(data.wall_in) fliplr(min(data.wall_in))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.wall_in)-273.15,'k','linewidth',1.5);

% title('Wall; inner surface temperature');
xlim([3 27]);      xlabel('Time'); 
ylim([16 32]);      ylabel('Temperature [^\circC]');
xticks([3:12:27]);
xticklabels({'Noon','Midnight','Noon'});
yticks(16:8:32);


subplot(2,2,2); hold on
% measurement
patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.N_wall_out(timeIdx)'+hourly.std.N_wall_out(timeIdx)',...
    fliplr(hourly.mean.N_wall_out(timeIdx)'-hourly.std.N_wall_out(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.N_wall_out(timeIdx), 'k');  

patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.S_wall_out(timeIdx)'+hourly.std.S_wall_out(timeIdx)',...
    fliplr(hourly.mean.S_wall_out(timeIdx)'-hourly.std.S_wall_out(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.S_wall_out(timeIdx), 'k');  


% prediction
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [cross.T_wall_out.ci_max,  fliplr(cross.T_wall_out.ci_min)],[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.7);
plot(t_averaged+dt/2, cross.T_wall_out.mean, 'r', 'linewidth',2);

patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [single.T_wall_out.ci_max,  fliplr(single.T_wall_out.ci_min)],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.7);
plot(t_averaged+dt/2, single.T_wall_out.mean, 'b', 'linewidth',2);



% title('Wall; outer surface temperature');
xlim([3 27]);      xlabel('Time'); 
ylim([16 32]);      ylabel('Temperature [^\circC]');
xticks([3:12:27]);
xticklabels({'Noon','Midnight','Noon'});
yticks(16:8:32);


% roof surface temperatures

% figure();
subplot(2,2,3); hold on
% measurement
patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.Roof_in(timeIdx)'+hourly.std.Roof_in(timeIdx)',...
    fliplr(hourly.mean.Roof_in(timeIdx)'-hourly.std.Roof_in(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.Roof_in(timeIdx), 'k', 'linewidth',1.5);  

% prediction
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [cross.T_roof_in.ci_max,  fliplr(cross.T_roof_in.ci_min)],[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, cross.T_roof_in.mean, 'r', 'linewidth',2);
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [single.T_roof_in.ci_max,  fliplr(single.T_roof_in.ci_min)],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, single.T_roof_in.mean, 'b', 'linewidth',2);


% title('Roof; inner surface temperature');
xlim([3 27]);      xlabel('Time'); 
ylim([10 60]);      ylabel('Temperature [^\circC]');
xticks([3 15 27]);
xticklabels({'Noon','Midnight','Noon'});


subplot(2,2,4); hold on
% measurement
patch([0.5:27.5, fliplr(0.5:27.5)],...
    [hourly.mean.Roof_out(timeIdx)'+hourly.std.Roof_out(timeIdx)',...
    fliplr(hourly.mean.Roof_out(timeIdx)'-hourly.std.Roof_out(timeIdx)')],...
    [0.8 0.8 0.8],'edgecolor','none','facealpha',0.5);
plot(0.5:27.5, hourly.mean.Roof_out(timeIdx), 'k', 'linewidth',1.5);  

% prediction
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [cross.T_roof_out.ci_max,  fliplr(cross.T_roof_out.ci_min)],[1.0 0.8 0.8],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, cross.T_roof_out.mean, 'r', 'linewidth',2);
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [single.T_roof_out.ci_max,  fliplr(single.T_roof_out.ci_min)],[0.8 0.8 1.0],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, single.T_roof_out.mean, 'b', 'linewidth',2);



% title('Roof: outer surface temperature');
xlim([3 27]);      xlabel('Time'); 
ylim([10 60]);      ylabel('Temperature [^\circC]');
xticks([3:12:27]);
xticklabels({'Noon','Midnight','Noon'});








