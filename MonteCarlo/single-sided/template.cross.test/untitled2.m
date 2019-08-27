
load('/home/yunjaeh/OpenFOAM/yunjaeh-4.0/run/UQ/uq_2019/integral_time_stamp.mat');     % load time stamp
output_nominal = dlmread('./result_nominal/OUTPUT_FILTERED.dat',' ',1,0);

output_roof_inclination = dlmread('./result_roof_inclination/OUTPUT_FILTERED.dat',' ',1,0);
output_rad_roof_floor = dlmread('./result_radiation_roof_floor/OUTPUT_FILTERED.dat',' ',1,0);
output_reflectance = dlmread('./result_reflectance/OUTPUT_FILTERED.dat',' ',1,0);
output_convection = dlmread('./result_convection/OUTPUT_FILTERED.dat',' ',1,0);
output_temp = dlmread('./workspace/OUTPUT_FILTERED.dat',' ',1,0);


figure(); 
subplot(2,3,1); hold on
    plot(t_stamp, output_nominal(:,1)-273.15,'k');
    plot(t_stamp, output_roof_inclination(:,1)-273.15,'b');
    plot(t_stamp, output_rad_roof_floor(:,1)-273.15,'c');
    plot(t_stamp, output_reflectance(:,1)-273.15,'r');
    plot(t_stamp, output_convection(:,1)-273.15,'g');

%     plot(t_stamp, output_temp(:,1)-273.15,'r.-');
    legend('Original model','Roof inclination','Radiation to floor','Roof reflectivity','Convection');
    xlabel('Time stamp');   ylabel('Temperature [C]');
    xlim([0 24]);   xticks(0:12:24);    xticklabels({'Noon','Midnight','Noon'});
    title('Indoor air temperature');


subplot(2,3,2); hold on
    plot(t_stamp, output_nominal(:,3)-273.15,'k');
    plot(t_stamp, output_roof_inclination(:,3)-273.15,'b');
    plot(t_stamp, output_rad_roof_floor(:,3)-273.15,'c');
    plot(t_stamp, output_reflectance(:,3)-273.15,'r');
    plot(t_stamp, output_convection(:,3)-273.15,'g');

%     plot(t_stamp, output_temp(:,3)-273.15,'r.-');
    xlabel('Time stamp');    ylabel('Temperature [C]');
    xlim([0 24]);   xticks(0:12:24);    xticklabels({'Noon','Midnight','Noon'});
    title('Wall inner surface temperature');

subplot(2,3,3); hold on
    plot(t_stamp, output_nominal(:,4)-273.15,'k');
    plot(t_stamp, output_roof_inclination(:,4)-273.15,'b');
    plot(t_stamp, output_rad_roof_floor(:,4)-273.15,'c');
    plot(t_stamp, output_reflectance(:,4)-273.15,'r');
    plot(t_stamp, output_convection(:,4)-273.15,'g');
    
%     plot(t_stamp, output_temp(:,4)-273.15,'r.-');
    xlabel('Time stamp');    ylabel('Temperature [C]');
    xlim([0 24]);   xticks(0:12:24);    xticklabels({'Noon','Midnight','Noon'});
    title('Wall outer surface temperature');
    
    
subplot(2,3,5); hold on
    plot(t_stamp, output_nominal(:,6)-273.15,'k');
    plot(t_stamp, output_roof_inclination(:,6)-273.15,'b');
    plot(t_stamp, output_rad_roof_floor(:,6)-273.15,'c');
    plot(t_stamp, output_reflectance(:,6)-273.15,'r');
    plot(t_stamp, output_convection(:,6)-273.15,'g');
    
%     plot(t_stamp, output_temp(:,6)-273.15,'r.-');
    xlabel('Time stamp');    ylabel('Temperature [C]');
    xlim([0 24]);   xticks(0:12:24);    xticklabels({'Noon','Midnight','Noon'});
    title('Roof inner surface temperature');

subplot(2,3,6); hold on
    plot(t_stamp, output_nominal(:,7)-273.15,'k');
    plot(t_stamp, output_roof_inclination(:,7)-273.15,'b');
    plot(t_stamp, output_rad_roof_floor(:,7)-273.15,'c');
    plot(t_stamp, output_reflectance(:,7)-273.15,'r');
    plot(t_stamp, output_convection(:,7)-273.15,'g');

%     plot(t_stamp, output_temp(:,7)-273.15,'r.-');
    xlabel('Time stamp');    ylabel('Temperature [C]');
    xlim([0 24]);   xticks(0:12:24);    xticklabels({'Noon','Midnight','Noon'});
    title('Roof outer surface temperature');
