clear;
clc;
%%% ACH comparison
load('/home/yunjaeh/github/Bangladesh_measurement/ACH/ach_post_process.mat');
ACH= ACH_mean_rms;

% Window / Vent	
%   0205, 23:54 – 00:30 
%   0206, 00:35 – 01:11
% Skylight / Vent	
%   0205, 02:06 – 02:45 
%   0205, 03:42 – 04:17
% Skylight / Window
%   0211, 00:11 – 00:42 
%   0211, 03:16 – 03:42 
%   0211, 03:46 – 04:10
% Skylight / Floor vent
%   0209, 22:10 – 22:45 
%   0209, 22:50 – 23:22 
%   0209, 23:30 – 23:59 
%   0211, 01:06 – 01:43


% load prediction data

timing = [23+54/60,   24+30/60;...    % WV 1
    24+35/60,   25+11/60;...    % WV 2
    26+6/60,    26+45/60;...    % SV 1
    27+42/60,   28+17/60;...    % SV 2
    24+11/60,   24+42/60;...    % SW 1
    27+16/60,   27+42/60;...    % SW 2
    27+46/60,   28+10/60;...    % SW 3
    22+10/60,   22+45/60;...    % SFV 1
    22+50/60,   23+22/60;...    % SFV 2
    23+30/60,   23+59/60];        % SFV 3

load('data_v3/wv/data_summary.mat');     wv_single = data;
load('data_v3/sv/data_summary.mat');     sv_single = data;
load('data_v3/sw/data_summary.mat');     sw_single = data;
load('data_v3/sfv/data_summary.mat');    sfv_single = data;

load('../cross/data_v1/wv/data_summary.mat');     wv_cross = data;
load('../cross/data_v1/sv/data_summary.mat');     sv_cross = data;
load('../cross/data_v1/sw/data_summary.mat');     sw_cross = data;
load('../cross/data_v1/sfv/data_summary.mat');    sfv_cross = data;




%%
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/time_stamp3.mat');     % load time stamp
t_patch = [t_stamp', fliplr(t_stamp')];

vol_house = 17.72;
wv_single.ach = wv_single.vent_rate*3600/vol_house;
sv_single.ach = sv_single.vent_rate*3600/vol_house;
sw_single.ach = sw_single.vent_rate*3600/vol_house;
sfv_single.ach = sfv_single.vent_rate*3600/vol_house;

wv_cross.ach = wv_cross.vent_rate*3600/vol_house;
sv_cross.ach = sv_cross.vent_rate*3600/vol_house;
sw_cross.ach = sw_cross.vent_rate*3600/vol_house;
sfv_cross.ach = sfv_cross.vent_rate*3600/vol_house;


% for i=1:2000
%     wv.ach(i,:) = wv.ach(i,:) + wv.input(i,7);
%     sv.ach(i,:) = sv.ach(i,:) + sv.input(i,7);
%     sw.ach(i,:) = sw.ach(i,:) + sw.input(i,7);
%     sfv.ach(i,:) = sfv.ach(i,:) + sfv.input(i,7);
% end


figure();
subplot(2,2,1); hold on
patch(t_patch, [mean(wv_single.ach)+2*std(wv_single.ach), fliplr(mean(wv_single.ach)-2*std(wv_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(wv_single.ach)+std(wv_single.ach), fliplr(mean(wv_single.ach)-std(wv_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(wv_single.ach),'b','linewidth',2);
title('W/V');

% experiment result
for i=1:2
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end




subplot(2,2,2); hold on
patch(t_patch, [mean(sv_single.ach)+2*std(sv_single.ach), fliplr(mean(sv_single.ach)-2*std(sv_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(sv_single.ach)+std(sv_single.ach), fliplr(mean(sv_single.ach)-std(sv_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(sv_single.ach),'b','linewidth',2);
title('S/V');
for i=3:4
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end


subplot(2,2,3); hold on
patch(t_patch, [mean(sw_single.ach)+2*std(sw_single.ach), fliplr(mean(sw_single.ach)-2*std(sw_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(sw_single.ach)+std(sw_single.ach), fliplr(mean(sw_single.ach)-std(sw_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(sw_single.ach),'b','linewidth',2);
title('S/W');
for i=5:7
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end



subplot(2,2,4); hold on
patch(t_patch, [mean(sfv_single.ach)+2*std(sfv_single.ach), fliplr(mean(sfv_single.ach)-2*std(sfv_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(sfv_single.ach)+std(sfv_single.ach), fliplr(mean(sfv_single.ach)-std(sfv_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(sfv_single.ach),'b','linewidth',2);
title('S/FV');
for i=8:10
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end


for i=1:4
   subplot(2,2,i);
   xlim([12 36]);
   xticks([12 24 36]);
   xticklabels({'Noon','Midnight','Noon'});
   ylabel('ACH');
end


%%% cross ventilation

figure();
subplot(2,2,1); hold on
patch(t_patch, [mean(wv_cross.ach)+2*std(wv_cross.ach), fliplr(mean(wv_cross.ach)-2*std(wv_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(wv_cross.ach)+std(wv_cross.ach), fliplr(mean(wv_cross.ach)-std(wv_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(wv_cross.ach),'r','linewidth',2);
title('W/V');

% experiment result
for i=1:2
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end




subplot(2,2,2); hold on
patch(t_patch, [mean(sv_cross.ach)+2*std(sv_cross.ach), fliplr(mean(sv_cross.ach)-2*std(sv_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sv_cross.ach)+std(sv_cross.ach), fliplr(mean(sv_cross.ach)-std(sv_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(sv_cross.ach),'r','linewidth',2);
title('S/V');
for i=3:4
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end


subplot(2,2,3); hold on
patch(t_patch, [mean(sw_cross.ach)+2*std(sw_cross.ach), fliplr(mean(sw_cross.ach)-2*std(sw_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sw_cross.ach)+std(sw_cross.ach), fliplr(mean(sw_cross.ach)-std(sw_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(sw_cross.ach),'r','linewidth',2);
title('S/W');
for i=5:7
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end



subplot(2,2,4); hold on
patch(t_patch, [mean(sfv_cross.ach)+2*std(sfv_cross.ach), fliplr(mean(sfv_cross.ach)-2*std(sfv_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sfv_cross.ach)+std(sfv_cross.ach), fliplr(mean(sfv_cross.ach)-std(sfv_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(sfv_cross.ach),'r','linewidth',2);
title('S/FV');
for i=8:10
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end


for i=1:4
   subplot(2,2,i);
   xlim([12 36]);
   xticks([12 24 36]);
   xticklabels({'Noon','Midnight','Noon'});
   ylabel('ACH');
   
end



%% 90 percent prediction interval
ci = 0.05;


ACH_prediction_single = zeros(size(ACH,1),3);
ACH_prediction_cross = zeros(size(ACH,1),3);

ACH_single = {wv_single.ach, wv_single.ach, sv_single.ach, sv_single.ach, ...
    sw_single.ach, sw_single.ach, sw_single.ach, sfv_single.ach, sfv_single.ach, sfv_single.ach };
ACH_cross = {wv_cross.ach, wv_cross.ach, sv_cross.ach, sv_cross.ach, ...
    sw_cross.ach, sw_cross.ach, sw_cross.ach, sfv_cross.ach, sfv_cross.ach, sfv_cross.ach };

for i=1:size(ACH,1)
    idx = timing(i,1) < t_stamp & t_stamp < timing(i,2);
    [F,X] = ecdf(reshape(ACH_single{i}(:,idx),1,[]));
    ACH_prediction_single(i,1) = mean(X);
    ACH_prediction_single(i,2) = max( X(F < ci) );
    ACH_prediction_single(i,3) = min( X(F > (1-ci) ) );
    [F,X] = ecdf(reshape(ACH_cross{i}(:,idx),1,[]));
    ACH_prediction_cross(i,1) = mean(X);
    ACH_prdiction_cross(i,2) = max( X(F < ci) );
    ACH_prediction_cross(i,3) = min( X(F > (1-ci) ) );
end

ACH_prediction_single(:,2) = ACH_prediction_single(:,2) - ACH_prediction_single(:,1);
ACH_prediction_single(:,3) = ACH_prediction_single(:,3) - ACH_prediction_single(:,1);

ACH_prediction_cross(:,2) = ACH_prediction_cross(:,2) - ACH_prediction_cross(:,1);
ACH_prediction_cross(:,3) = ACH_prediction_cross(:,3) - ACH_prediction_cross(:,1);

figure(); hold on
for i=1:size(ACH,1)
    plot([ACH(i,1), ACH(i,1)],[ACH_prediction_single(i,1), ACH_prediction_cross(i,1)],'k');
end

plot_single= errorbar(ACH(:,1), ACH_prediction_single(:,1), ACH_prediction_single(:,2),ACH_prediction_single(:,3),...
    ACH(:,2), ACH(:,2), 'bo','linewidth',1);
plot_cross= errorbar(ACH(:,1), ACH_prediction_cross(:,1), ACH_prediction_cross(:,2),ACH_prediction_cross(:,3),...
    ACH(:,2), ACH(:,2), 'ro','linewidth',1);

plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
xticks([0:5:50]);   yticks([0:5:50]);


legend([plot_single,plot_cross,plot_yx],'Single-sided', 'Cross' ,'y=x');  %,...
    %'location','southoutside','orientation','horizontal');
grid on
xlabel('ACH: experiment');
ylabel('ACH: prediction');
axis([0 25 0 50])


%% individual plots
% idExp = 1:2;    % wv
% idExp = 3:4;    % sv
% idExp = 5:7;    % sw
idExp = 8:10;    % sfv

figure(); hold on
for i=idExp
    plot([ACH(i,1), ACH(i,1)],[ACH_prediction_single(i,1), ACH_prediction_cross(i,1)],'k');
end
plot_single= errorbar(ACH(idExp,1), ACH_prediction_single(idExp,1), ACH_prediction_single(idExp,2),ACH_prediction_single(idExp,3),...
    ACH(idExp,2), ACH(idExp,2), 'bo','linewidth',1);
plot_cross= errorbar(ACH(idExp,1), ACH_prediction_cross(idExp,1), ACH_prediction_cross(idExp,2),ACH_prediction_cross(idExp,3),...
    ACH(idExp,2), ACH(idExp,2), 'ro','linewidth',1);

plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
xticks([0:5:50]);   yticks([0:5:50]);


% legend([plot_single,plot_cross,plot_yx],'Single-sided', 'Cross' ,'y=x',...
%     'location','southoutside','orientation','horizontal');
grid on
xlabel('ACH: experiment');
ylabel('ACH: prediction');
axis([0 25 0 50])








































