clear;  clc;
%%% ACH comparison
load('/home/yunjaeh/github/Bangladesh_measurement/ACH/ach_exp_day.mat');
ACH= ACH_mean_rms;


% load prediction data

% timing = [15+11/60,   15+50/60;...    % SFV 1
%     16+19/60,   16+54/60;...    % SFV 2
%     15+3/60,    15+39/60;...    % SV 1
%     15+55/60,    16+20/60;...    % SV 2
%     16+26/60,   17+1/60;...    % SV 3
%     14+51/60,   15+27/60;...    % SW 1
%     15+29/60,   16+4/60;...    % SW 2
%     15+4/60,    15+40/60;...    % WV 1
%     15+56/60,   16+30/60];

timing = [15+11/60,   15+50/60;...    % SFV 1
    16+19/60,   16+54/60;...    % SFV 2
    15+3/60,    15+39/60;...    % SV 1
    15+55/60,    16+20/60;...    % SV 2
    16+26/60,   17+1/60;...    % SV 3
    15+4/60,    15+40/60;...    % WV 1
    15+56/60,   16+30/60; ...     % WV 2
    14+51/60,   15+27/60;...    % SW 1
    15+29/60,   16+4/60];       % SW 2



%;...    % WV 2   
%    14+29/60,   15+7/60;...    % WV 3
%    15+15/60,   15+51/60];  % WV 4
timing = timing+3;

load('./single-sided/data_v6.vent/wv/data_summary.mat');     wv_single = data;
load('./single-sided/data_v6.vent/sv/data_summary.mat');     sv_single = data;
load('./single-sided/data_v6.vent/sw/data_summary.mat');     sw_single = data;
load('./single-sided/data_v6.vent/sfv/data_summary.mat');    sfv_single = data;

load('./cross/data_v6.vent/day_wv/data_summary.mat');     wv_cross = data;
load('./cross/data_v6.vent/day_sv/data_summary.mat');     sv_cross = data;
load('./cross/data_v6.vent/day_sw/data_summary.mat');     sw_cross = data;
load('./cross/data_v6.vent/day_sfv/data_summary.mat');    sfv_cross = data;



%%
load('/home/yunjaeh/github/UQ/MonteCarlo/cross/time_stamp4.mat');     % load time stamp
t_patch = [t_stamp', fliplr(t_stamp')];
idFig = [1, 1, 2, 2, 2, 3, 3, 4, 4];

vol_house = 17.72;
wv_single.ach = wv_single.vent_rate*3600/vol_house;
sv_single.ach = sv_single.vent_rate*3600/vol_house;
sw_single.ach = sw_single.vent_rate*3600/vol_house;
sfv_single.ach = sfv_single.vent_rate*3600/vol_house;

wv_cross.ach = wv_cross.vent_rate*3600/vol_house;
sv_cross.ach = sv_cross.vent_rate*3600/vol_house;
sw_cross.ach = sw_cross.vent_rate*3600/vol_house;
sfv_cross.ach = sfv_cross.vent_rate*3600/vol_house;


figure();
subplot(2,2,1); hold on
patch(t_patch, [mean(sfv_single.ach)+2*std(sfv_single.ach), fliplr(mean(sfv_single.ach)-2*std(sfv_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(sfv_single.ach)+std(sfv_single.ach), fliplr(mean(sfv_single.ach)-std(sfv_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(sfv_single.ach),'b','linewidth',2);
title('S/FV');
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
for i=3:5
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end

subplot(2,2,3); hold on
patch(t_patch, [mean(wv_single.ach)+2*std(wv_single.ach), fliplr(mean(wv_single.ach)-2*std(wv_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(wv_single.ach)+std(wv_single.ach), fliplr(mean(wv_single.ach)-std(wv_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(wv_single.ach),'b','linewidth',2);

title('W/V');

% experiment result
for i=6:7
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end

subplot(2,2,4); hold on
patch(t_patch, [mean(sw_single.ach)+2*std(sw_single.ach), fliplr(mean(sw_single.ach)-2*std(sw_single.ach))],...
    [0.9 0.9 1.0],'edgecolor','none');
patch(t_patch, [mean(sw_single.ach)+std(sw_single.ach), fliplr(mean(sw_single.ach)-std(sw_single.ach))],...
    [0.8 0.8 1.0],'edgecolor','none');
plot(t_stamp, mean(sw_single.ach),'b','linewidth',2);
title('S/W');
for i=8:9
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
   xlim([3 27]);
   xticks([3:12:27]);
   xticklabels({'Midnight','Noon','Midnight'});
   ylabel('ACH');
   
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       cross ventilation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

figure();
subplot(2,2,1); hold on
% patch(t_patch, [mean(sfv_cross2.ach)+2*std(sfv_cross2.ach), fliplr(mean(sfv_cross2.ach)-2*std(sfv_cross2.ach))],...
%     [0.9 0.9 1.0],'edgecolor','none','facealpha',0.5);

patch(t_patch, [mean(sfv_cross.ach)+2*std(sfv_cross.ach), fliplr(mean(sfv_cross.ach)-2*std(sfv_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sfv_cross.ach)+std(sfv_cross.ach), fliplr(mean(sfv_cross.ach)-std(sfv_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');
% plot(t_stamp, mean(sfv_cross2.ach),'b','linewidth',2);
plot(t_stamp, mean(sfv_cross.ach),'r','linewidth',2);
title('S/FV');
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
% patch(t_patch, [mean(sv_cross2.ach)+std(sv_cross2.ach), fliplr(mean(sv_cross2.ach)-std(sv_cross2.ach))],...
%     [0.8 0.8 1.0],'edgecolor','none','facealpha',0.5);

patch(t_patch, [mean(sv_cross.ach)+2*std(sv_cross.ach), fliplr(mean(sv_cross.ach)-2*std(sv_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sv_cross.ach)+std(sv_cross.ach), fliplr(mean(sv_cross.ach)-std(sv_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');

% plot(t_stamp, mean(sv_cross2.ach),'b','linewidth',2);
plot(t_stamp, mean(sv_cross.ach),'r','linewidth',2);
title('S/V');
for i=3:5
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end


subplot(2,2,3); hold on
% patch(t_patch, [mean(wv_cross2.ach)+2*std(wv_cross2.ach), fliplr(mean(wv_cross2.ach)-2*std(wv_cross2.ach))],...
%     [0.9 0.9 1.0],'edgecolor','none','facealpha',0.5);

patch(t_patch, [mean(wv_cross.ach)+2*std(wv_cross.ach), fliplr(mean(wv_cross.ach)-2*std(wv_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(wv_cross.ach)+std(wv_cross.ach), fliplr(mean(wv_cross.ach)-std(wv_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');
plot(t_stamp, mean(wv_cross.ach),'r','linewidth',2);


% plot(t_stamp, mean(wv_cross2.ach),'b','linewidth',2);
title('W/V');

% experiment result
for i=8:9
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+2*ACH(i,2),ACH(i,1)+2*ACH(i,2),ACH(i,1)-2*ACH(i,2),ACH(i,1)-2*ACH(i,2) ],...
    [0.7 0.7 0.7],'edgecolor','none');
    patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
        [ACH(i,1)+ACH(i,2),ACH(i,1)+ACH(i,2),ACH(i,1)-ACH(i,2),ACH(i,1)-ACH(i,2) ],...
    [0.5 0.5 0.5],'edgecolor','none');
    plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
end

subplot(2,2,4); hold on
% patch(t_patch, [mean(sw_cross2.ach)+2*std(sw_cross2.ach), fliplr(mean(sw_cross2.ach)-2*std(sw_cross2.ach))],...
%     [0.9 0.9 1.0],'edgecolor','none','facealpha',0.5);

patch(t_patch, [mean(sw_cross.ach)+2*std(sw_cross.ach), fliplr(mean(sw_cross.ach)-2*std(sw_cross.ach))],...
    [1.0 0.9 0.9],'edgecolor','none');
patch(t_patch, [mean(sw_cross.ach)+std(sw_cross.ach), fliplr(mean(sw_cross.ach)-std(sw_cross.ach))],...
    [1.0 0.8 0.8],'edgecolor','none');

% plot(t_stamp, mean(sw_cross2.ach),'b','linewidth',2);
plot(t_stamp, mean(sw_cross.ach),'r','linewidth',2);
title('S/W');
for i=8:9
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
   xlim([3 27]);
   xticks([3:12:27]);
   xticklabels({'Midnight','Noon','Midnight'});
   ylabel('ACH');
   
end



%% 95 percent prediction interval
% timing = [15+11/60,   15+50/60;...    % SFV 1
%     16+19/60,   16+54/60;...    % SFV 2
%     15+3/60,    15+39/60;...    % SV 1
%     15+55/60,    16+20/60;...    % SV 2
%     16+26/60,   17+1/60;...    % SV 3
%     14+51/60,   15+27/60;...    % SW 1
%     15+29/60,   16+4/60;...    % SW 2
%     15+4/60,    15+40/60;...    % WV 1
%     15+56/60,   16+30/60];

ci = 0.025;

ACH_prediction_single = zeros(size(ACH,1),3);
ACH_prediction_cross = zeros(size(ACH,1),3);

ACH_single = {sfv_single.ach, sfv_single.ach, sv_single.ach, sv_single.ach, sv_single.ach,...
    wv_single.ach, wv_single.ach, sw_single.ach, sw_single.ach};
ACH_cross = {sfv_cross.ach,sfv_cross.ach, sv_cross.ach,sv_cross.ach, sv_cross.ach, ...
    wv_cross.ach, wv_cross.ach, sw_cross.ach, sw_cross.ach };

% ACH_cross2 = {wv_cross2.ach, wv_cross2.ach, sv_cross2.ach, sv_cross2.ach, ...
%     sw_cross2.ach, sw_cross2.ach, sw_cross2.ach, sfv_cross2.ach, sfv_cross2.ach, sfv_cross2.ach };

for i=1:9
    idx = timing(i,1) < t_stamp & t_stamp < timing(i,2);
    [F,X] = ecdf(reshape(ACH_single{i}(:,idx),1,[]));
    ACH_prediction_single(i,1) = mean(X);
    ACH_prediction_single(i,2) = max( X(F < ci) );
    ACH_prediction_single(i,3) = min( X(F > (1-ci) ) );
    [F,X] = ecdf(reshape(ACH_cross{i}(:,idx),1,[]));
    ACH_prediction_cross(i,1) = mean(X);
    ACH_prediction_cross(i,2) = max( X(F < ci) );
    ACH_prediction_cross(i,3) = min( X(F > (1-ci) ) );
end
% 
% figure();
% for i=1:length(ACH_cross2)
%     idx = timing(i,1) < t_stamp & t_stamp < timing(i,2);
%     subplot(2,5,i);
%     [F,X] = ecdf(reshape(ACH_cross{i}(:,idx),1,[]));
%     histogram(X,50,'facecolor','b','normalization','pdf'); hold on
%     [F,X] = ecdf(reshape(ACH_cross2{i}(:,idx),1,[]));
%     histogram(X,50,'facecolor','r','normalization','pdf');
%     ACH_prediction_cross2(i,1) = mean(X);
%     ACH_prediction_cross2(i,2) = max( X(F < ci) );
%     ACH_prediction_cross2(i,3) = min( X(F > (1-ci) ) );
% end
   

ACH_prediction_single(:,2) = ACH_prediction_single(:,2) - ACH_prediction_single(:,1);
ACH_prediction_single(:,3) = ACH_prediction_single(:,3) - ACH_prediction_single(:,1);

ACH_prediction_cross(:,2) = ACH_prediction_cross(:,2) - ACH_prediction_cross(:,1);
ACH_prediction_cross(:,3) = ACH_prediction_cross(:,3) - ACH_prediction_cross(:,1);

figure(); hold on
for i=1:size(ACH,1)
    plot([ACH(i,1), ACH(i,1)],[ACH_prediction_single(i,1), ACH_prediction_cross(i,1)],'k');
end

% line y=x
plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
% plot(0:50, (1-0.25)*(0:50), 'k--','linewidth',1);
% plot(0:50, (1+0.25)*(0:50), 'k--','linewidth',1);


% single-sided 
plot_single= errorbar(ACH(:,1), ACH_prediction_single(:,1), ACH_prediction_single(:,2),ACH_prediction_single(:,3),...
    ACH(:,2), ACH(:,2), 'bo','linewidth',1.5);

% cross
plot_cross= errorbar(ACH(:,1), ACH_prediction_cross(:,1), ACH_prediction_cross(:,2),ACH_prediction_cross(:,3),...
    ACH(:,2), ACH(:,2), 'ro','linewidth',1.5);

legend([plot_single,plot_cross],'Single-sided', 'Cross', 'location','southeast');
legend boxoff
text(17, 17, 'y = x', 'BackgroundColor', 'w', 'rotation', 40, 'FontSize', 15);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:5:50]);   ylabel('ACH: prediction');

grid on
axis([0 20 0 20])


%%
figure(); 
hold on
for i=1:size(ACH,1)
    plot([ACH_best_fit(i), ACH_best_fit(i)],[ACH_prediction_single(i,1), ACH_prediction_cross(i,1)],'k');
end

% line y=x
plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);

% single-sided 
plot_single= errorbar(ACH_best_fit, ACH_prediction_single(:,1), ACH_prediction_single(:,2),ACH_prediction_single(:,3),...
    'bx','linewidth',1.5);

% cross
plot_cross= errorbar(ACH_best_fit, ACH_prediction_cross(:,1), ACH_prediction_cross(:,2),ACH_prediction_cross(:,3),...
    'rx','linewidth',1.5);

% plot_single.Color=[0.5 0.5 1.0];
% plot_cross.Color=[1.0 0.5 0.5];

legend([plot_single,plot_cross],'Single-sided', 'Cross', 'location','southeast');
legend boxoff
text(17, 17, 'y = x', 'BackgroundColor', 'w', 'rotation', 40, 'FontSize', 15);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:5:50]);   ylabel('ACH: prediction');

grid on
axis([0 25 0 25])


title('Best fit');


ACH_day.ACH = ACH;
ACH_day.ACH_best_fit = ACH_best_fit;
ACH_day.ACH_prediction_single = ACH_prediction_single;
ACH_day.ACH_prediction_cross = ACH_prediction_cross;
% save('ACH_day.mat','ACH_day');



%% individual plots
idExp = 1:2; temp_title='S/FV';  % sfv
% idExp = 3:5;  temp_title='S/V'; % sv
% idExp = 6:7;  temp_title='S/W'; % sw
% idExp = 8:9;    temp_title='W/V'; % wv

figure(); hold on
for i=idExp
    plot([ACH(i,1), ACH(i,1)],[ACH_prediction_single(i,1), ACH_prediction_cross(i,1)],'k');
end
plot_yx = plot(0:50, 0:50, 'k--','linewidth',1);
plot_single= errorbar(ACH(idExp,1), ACH_prediction_single(idExp,1), ACH_prediction_single(idExp,2),ACH_prediction_single(idExp,3),...
    ACH(idExp,2), ACH(idExp,2), 'bo','linewidth',1.5);
plot_cross= errorbar(ACH(idExp,1), ACH_prediction_cross(idExp,1), ACH_prediction_cross(idExp,2),ACH_prediction_cross(idExp,3),...
    ACH(idExp,2), ACH(idExp,2), 'ro','linewidth',1.5);


% for i=idExp
%     plot([ACH_best_fit(i), ACH_best_fit(i)],[ACH_prediction_single(i,1), ACH_prediction_cross(i,1)],'k');
% end
% plot_single_bf= errorbar(ACH_best_fit(idExp), ACH_prediction_single(idExp,1), ACH_prediction_single(idExp,2),ACH_prediction_single(idExp,3),...
%     'bx','linewidth',1.5);
% plot_cross_bf= errorbar(ACH_best_fit(idExp), ACH_prediction_cross(idExp,1), ACH_prediction_cross(idExp,2),ACH_prediction_cross(idExp,3),...
%     'rx','linewidth',1.5);
% plot_single_bf.Color=[0.5 0.5 1.0];
% plot_cross_bf.Color=[1.0 0.5 0.5];


% legend([plot_single,plot_cross,plot_single_bf,plot_cross_bf],...
%     'Single-sided', 'Cross','Single-sided (best-fit)', 'Cross (best-fit)',...
%     'location','southeast');
text(17, 17, 'y = x', 'BackgroundColor', 'w', 'rotation', 40, 'FontSize', 15);
xticks([0:5:50]);   xlabel('ACH: experiment');
yticks([0:5:50]);   ylabel('ACH: prediction');
% legend boxoff

grid on
axis([0 20 0 20])
title(temp_title);


%% convergence study
ci = 0.025;

dataConvergence = wv_single.ach;
idTest = 1;

idx = timing(idTest,1) < t_stamp & t_stamp < timing(idTest,2);
numSample = size(dataConvergence,1);

convMean = zeros(numSample,1);
convMax = zeros(numSample,1);
convMin = zeros(numSample,1);

for i=1:numSample
    [F,X] = ecdf(reshape(ACH_single{idTest}(1:i,idx),1,[]));
    convMean(i) = mean(X);
    convMin(i) = max( X(F < ci) );
    convMax(i) = min( X(F > (1-ci) ) );
end

%%

errMean = abs(convMean(2:end) - convMean(1:end-1))./convMean(2:end)*100;
errMin = abs(convMin(2:end) - convMin(1:end-1))./convMin(2:end)*100;
errMax = abs(convMax(2:end) - convMax(1:end-1))./convMax(2:end)*100;

figure();
hold on
plot(convMean, 'k');
plot(convMax,  'b');
plot(convMin,  'b');
xlabel('# of samples');
ylabel('ACH');
title('Convergence: ACH over # of samples');
ylim([5 15]);

figure();
subplot(3,1,1); hold on
plot(1:length(errMean), errMean);
plot([1 length(errMean)],[0.1 0.1],'k:');

ylim([0 1.0]);
xlabel('# of samples'); ylabel('% change');
title('Mean');

subplot(3,1,2);
 hold on
plot(1:length(errMin), errMin);
plot([1 length(errMin)],[0.1 0.1],'k:');

ylim([0 1.0]);
xlabel('# of samples'); ylabel('% change');
title('Min');

subplot(3,1,3);
 hold on
plot(1:length(errMax), errMax);
plot([1 length(errMax)],[0.1 0.1],'k:');

ylim([0 1.0]);
xlabel('# of samples'); ylabel('% change');
title('Max');

% plot(1:numSample, convMin, 'b');
% plot(1:numSample, convMax, 'b');



%% temperature trend
% load('/home/yunjaeh/github/Bangladesh_measurement/TemperatureWind/Data/MeasurementDataTable.mat');
targetDate = datetime(2019,2,6,12,0,0);    % wv
% targetDate = datetime(2019,2,5,12,0,0);    % sv
% targetDate = datetime(2019,2,11,12,0,0);    % sw
% targetDate = datetime(2019,2,10,12,0,0);    % sfv

data_single = wv_single;
data_cross  = wv_cross;

dt = 0.5;
t_averaged = 0:dt:(36-dt);
ci = 0.025;

for i= 1:length(t_averaged)
    idx = t_averaged(i) < t_stamp & t_stamp < (t_averaged(i)+dt);
    
    [f,x] = ecdf(reshape(data_single.temp_in(:,idx)-273.15,1,[]));
    T_in_single.mean(i) = mean(reshape(data_single.temp_in(:,idx),1,[]))-273.15;
    T_in_single.ci_min(i) = max( x(f < ci) );
    T_in_single.ci_max(i) = min( x(f > (1-ci) ) );

    [f,x] = ecdf(reshape(data_cross.temp_in(:,idx)-273.15,1,[]));
    T_in_cross.mean(i) = mean(reshape(data_cross.temp_in(:,idx),1,[]))-273.15;
    T_in_cross.ci_min(i) = max( x(f < ci) );
    T_in_cross.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(data_single.ach(:,idx),1,[]));
    ACH_s.mean(i) = mean(reshape(data_single.ach(:,idx),1,[]));
    ACH_s.ci_min(i) = max( x(f < ci) );
    ACH_s.ci_max(i) = min( x(f > (1-ci) ) );
    
    [f,x] = ecdf(reshape(data_cross.ach(:,idx),1,[]));
    ACH_c.mean(i) = mean(reshape(data_cross.ach(:,idx),1,[]));
    ACH_c.ci_min(i) = max( x(f < ci) );
    ACH_c.ci_max(i) = min( x(f > (1-ci) ) );
    
    

end

%%
% indoor air temperature
timeIdx = (targetDate-hours(36)) <= hourly.Time & hourly.Time <= targetDate ; 
 

figure();
% subplot(1,2,1);
hold on
% measurement
plot(0:36, hourly.mean.CT_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.NE_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.NW_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.SE_low(timeIdx), 'b'); 
plot(0:36, hourly.mean.SW_low(timeIdx), 'b'); 

plot(0:36, hourly.mean.CT_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.NE_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.NW_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.SE_mid(timeIdx), 'k'); 
plot(0:36, hourly.mean.SW_mid(timeIdx), 'k'); 

plot(0:36, hourly.mean.CT_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.NE_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.NW_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.SE_top(timeIdx), 'r'); 
plot(0:36, hourly.mean.SW_top(timeIdx), 'r'); 

xlim([12 36]);
xlabel('Time [hr]');
ylabel('Temperature [C]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});



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
    
   

%
% subplot(1,2,2); 
%%
figure();
hold on
% plot(t_averaged+dt/2, T_in_single.mean, 'b', 'linewidth',2);
% plot(t_averaged+dt/2, T_in_cross.mean, 'r', 'linewidth',2);


% patch([0.5:36.5, fliplr(0.5:36.5)], [tempIndoor.mean+tempIndoor.std,  fliplr(tempIndoor.mean-tempIndoor.std)],[0.6 0.6 0.6],...
%     'edgecolor','none','facealpha',0.5);
% plot(0.5:36.5, tempIndoor.mean, 'k', 'linewidth',2);
% plot(0:36, tempIndoor.mean, 'b', 'linewidth',2);


% prediction
%%% hourly data

patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_in_cross.ci_max,  fliplr(T_in_cross.ci_min)],[1.0 0.6 0.6],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, T_in_cross.mean, 'r', 'linewidth',2);
xlim([12 36]);
yticks(15:5:30);
ylim([16 32]);
xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});




% 
% figure();
% hold on
% patch([0.5:36.5, fliplr(0.5:36.5)], [tempIndoor.mean+tempIndoor.std,  fliplr(tempIndoor.mean-tempIndoor.std)],[0.6 0.6 0.6],...
%     'edgecolor','none','facealpha',0.5);
% plot(0.5:36.5, tempIndoor.mean, 'k', 'linewidth',2);
% plot(0:36, tempIndoor.mean, 'b', 'linewidth',2);


patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [T_in_single.ci_max,  fliplr(T_in_single.ci_min)],[0.6 0.6 1.0],...
    'edgecolor','none','facealpha',0.5);
plot(t_averaged+dt/2, T_in_single.mean, 'b', 'linewidth',2);


%%% minutely data
% patch([t_stamp' fliplr(t_stamp')], [max(data.temp_in) fliplr(min(data.temp_in))]-273.15,[0.8 0.8 0.8],...
%     'edgecolor','none','facealpha',0.5);
% plot(t_stamp, mean(data.temp_in)-273.15,'k','linewidth',2);

% legend('Measurement','Prediction');
xlim([12 36]);
yticks(15:5:30);
ylim([16 32]);
% xlabel('Time');
ylabel('Temperature [^\circC]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});



%%


% pF = 2;
% figure(); hold on
% patch(t_patch, [mean(data_cross.ach)+pF*std(data_cross.ach), fliplr(mean(data_cross.ach)-pF*std(data_cross.ach))],...
%     [1.0 0.7 0.7],'edgecolor','none','facealpha',0.7);
% plot(t_stamp, mean(data_cross.ach),'r','linewidth',2);
% 
% patch(t_patch, [mean(data_single.ach)+pF*std(data_single.ach), fliplr(mean(data_single.ach)-pF*std(data_single.ach))],...
%     [0.7 0.7 1.0],'edgecolor','none','facealpha',0.7);
% plot(t_stamp, mean(data_single.ach),'b','linewidth',2);
% 

figure();hold on
patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [ACH_s.ci_max,  fliplr(ACH_s.ci_min)],[0.7 0.7 1.0],...
    'edgecolor','none','facealpha',0.7);
plot(t_averaged+dt/2, ACH_s.mean, 'b', 'linewidth',2);

patch([t_averaged+dt/2, fliplr(t_averaged+dt/2)], [ACH_c.ci_max,  fliplr(ACH_c.ci_min)],[1.0 0.7 0.7],...
    'edgecolor','none','facealpha',0.7);
plot(t_averaged+dt/2, ACH_c.mean, 'r', 'linewidth',2);



% % experiment result
% for i=5:7
%     patch([timing(i,1),timing(i,2),timing(i,2),timing(i,1)],...
%         [ACH(i,1)+pF*ACH(i,2),ACH(i,1)+pF*ACH(i,2),ACH(i,1)-pF*ACH(i,2),ACH(i,1)-pF*ACH(i,2) ],...
%     [0.5 0.5 0.5],'edgecolor','none','facealpha',0.7);
%     plot([timing(i,1) timing(i,2)],[ACH(i,1) ACH(i,1)] ,'k','linewidth',2);
% end

xlim([12 36]);
% ylim([0 15]);

xlabel('Time');
ylabel('ACH [1/hr]');
xticks([12 24 36]);
xticklabels({'Noon','Midnight','Noon'});
yticks([0:10:20])



















