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

% load('data_night/wv/data_summary.mat');     wv = data;
% load('data_night/sv/data_summary.mat');     sv = data;
% load('data_night/sw/data_summary.mat');     sw = data;
% load('data_night/sfv/data_summary.mat');    sfv = data;
load('wv.v2/data_summary.mat');     wv = data;
load('sv.v2/data_summary.mat');     sv = data;
load('sw.v2/data_summary.mat');     sw = data;
load('sfv.v2/data_summary.mat');    sfv = data;

%%
load('/home/yunjaeh/github/UQ/MonteCarlo/single-sided/time_stamp3.mat');     % load time stamp
t_patch = [t_stamp', fliplr(t_stamp')];

vol_house = 17.72;
wv.ach = wv.vent_rate*3600/vol_house;
sv.ach = sv.vent_rate*3600/vol_house;
sw.ach = sw.vent_rate*3600/vol_house;
sfv.ach = sfv.vent_rate*3600/vol_house;

% for i=1:2000
%     wv.ach(i,:) = wv.ach(i,:) + wv.input(i,7);
%     sv.ach(i,:) = sv.ach(i,:) + sv.input(i,7);
%     sw.ach(i,:) = sw.ach(i,:) + sw.input(i,7);
%     sfv.ach(i,:) = sfv.ach(i,:) + sfv.input(i,7);
% end


figure();
subplot(2,2,1); hold on
patch(t_patch, [mean(wv.ach)+2*std(wv.ach), fliplr(mean(wv.ach)-2*std(wv.ach))],...
    [0.9 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(wv.ach)+std(wv.ach), fliplr(mean(wv.ach)-std(wv.ach))],...
    [0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(wv.ach),'k','linewidth',2);
title('W/V');

% experiment result
for i=1:2
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.8 0.8 1.0],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.6 0.6 1.0],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'b','linewidth',2);
end




subplot(2,2,2); hold on
patch(t_patch, [mean(sv.ach)+2*std(sv.ach), fliplr(mean(sv.ach)-2*std(sv.ach))],...
    [0.9 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sv.ach)+std(sv.ach), fliplr(mean(sv.ach)-std(sv.ach))],...
    [0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(sv.ach),'k','linewidth',2);
title('S/V');
for i=3:4
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.8 0.8 1.0],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.6 0.6 1.0],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'b','linewidth',2);
end


subplot(2,2,3); hold on
patch(t_patch, [mean(sw.ach)+2*std(sw.ach), fliplr(mean(sw.ach)-2*std(sw.ach))],...
    [0.9 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sw.ach)+std(sw.ach), fliplr(mean(sw.ach)-std(sw.ach))],...
    [0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(sw.ach),'k','linewidth',2);
title('S/W');
for i=5:7
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.8 0.8 1.0],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.6 0.6 1.0],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'b','linewidth',2);
end



subplot(2,2,4); hold on
patch(t_patch, [mean(sfv.ach)+2*std(sfv.ach), fliplr(mean(sfv.ach)-2*std(sfv.ach))],...
    [0.9 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sfv.ach)+std(sfv.ach), fliplr(mean(sfv.ach)-std(sfv.ach))],...
    [0.8 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(sfv.ach),'k','linewidth',2);
title('S/FV');
for i=8:10
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.8 0.8 1.0],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.6 0.6 1.0],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'b','linewidth',2);
end


for i=1:4
   subplot(2,2,i);
   xlim([12 36]);
   xticks([12 24 36]);
   xticklabels({'Noon','Midnight','Noon'});
   ylabel('ACH');
end










