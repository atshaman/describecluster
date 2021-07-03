# Keycloak
location /auth/ {
  proxy_pass         http://keycloak.keycloak.svc.cluster.local/auth/;
  if ($uri ~ "/auth/realms/master/login-actions/authenticate") {
  add_header    Set-Cookie         "JSESSIONID=;path=/camunda;HttpOnly;expires=Thu, Jan 01 1970 00:00:00 UTC";
}
  proxy_set_header    Host               $host;
  proxy_set_header    X-Real-IP          $remote_addr;
  proxy_set_header    X-Forwarded-For    $proxy_add_x_forwarded_for;
  proxy_set_header    X-Forwarded-Host   $host;
  proxy_set_header    X-Forwarded-Server $host;
  proxy_set_header    X-Forwarded-Port   $server_port;
  proxy_set_header    X-Forwarded-Proto  $scheme;
}

# Frontend

location / {
  proxy_pass     http://root-spa.frontend.svc.cluster.local:80/;
  include        conf.d/proxy_headers.inc;
}

location /json/ {
  proxy_pass     http://json-server.frontend.svc.cluster.local:80/;
  include        conf.d/proxy_headers.inc;
}
location /mstorage/ {
  proxy_pass     http://zif-mnemoschemes-storage.frontend.svc.cluster.local:8080/mstorage/;
}

location /hostDashboardDx {
  proxy_pass  http://zui-app-dashboard-dx.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}


location /hostQA/ {
  proxy_pass  http://ui-qa.zqa.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}
location /zqa-samples/ {
  proxy_pass  http://samples.zqa.svc.cluster.local:5000/;
  include conf.d/proxy_headers.inc;
}
location /zqa-spc/ {
  proxy_pass     http://zqa-spc.zqa.svc.cluster.local:5000/zqa-spc/;
  include        conf.d/proxy_headers.inc;
}

location /zqa-inspection/ {
  proxy_pass     http://zqa-inspection.zqa.svc.cluster.local:5000/zqa-inspection/;
  include        conf.d/proxy_headers.inc;
}


#location ~/hostPS/(.*)$ {
#  proxy_pass  http://ui-ps.zps.svc.cluster.local:8080/$1;
#  include conf.d/proxy_headers.inc;
#}
location /hostPS/ {
  proxy_pass  http://ui-ps.zps.svc.cluster.local:8080/;
  include conf.d/proxy_headers.inc;
}

location /hostEe/ {
  proxy_pass  http://zui-app-ee.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}


###PS####
location /hostPSStandSpcEpm {
  proxy_pass  http://ps-stand-spc-epm-ui.zps.svc.cluster.local:8080/;
  include conf.d/proxy_headers.inc;
}

location /hostPSStandCoEpm {
  proxy_pass  http://zui-app-ps-stand-co-epm.frontend.svc.cluster.local:8080/;
  include conf.d/proxy_headers.inc;
}

location /hostStatisticalControl  {
  proxy_pass  http://zui-pkg-statistical-control.frontend.svc.cluster.local/;
  include conf.d/proxy_headers.inc;
}

location /hostPSMasterSpcEpm {
  proxy_pass  http://ps-master-spc-epm-ui.zps.svc.cluster.local:8080/;
  include conf.d/proxy_headers.inc;
  add_header 'Access-Control-Allow-Origin' '*';
  add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, DELETE, PATCH, OPTIONS' always;
  add_header 'Access-Control-Allow-Headers' 'X-Requested-With, content-type, Authorization' always;
  add_header Content-Security-Policy "frame-ancestors 172.22.159.225" always;

}
#location /ps/ {
#  proxy_pass  http://ui-ps.zps.svc.cluster.local:8080/;
#  include conf.d/proxy_headers.inc;
#}


location /psnifi/ {
  proxy_pass       http://nifi.nifi.svc.cluster.local:1337/;
  include          conf.d/proxy_headers.inc;
  proxy_set_header X-ProxyScheme http;
  proxy_set_header X-ProxyPort 80;
  proxy_set_header X-ProxyContextPath /psnifi;
}

 location /hostPSPlanning/ {
    proxy_pass http://ps-planning.zps.svc.cluster.local:8080/;
    include conf.d/proxy_headers.inc;
}

location /hostPSWorks/ {
   proxy_pass http://ps-works-ui.zps.svc.cluster.local:8080/;
   include conf.d/proxy_headers.inc;
}


location /hostPSStore/ {
   proxy_pass http://ps-store.zps.svc.cluster.local:8080/;
   #include conf.d/proxy_headers.inc;
    proxy_redirect    off;
    proxy_set_header  Host                  $host;
    proxy_set_header  X-Real-IP             $remote_addr;
    proxy_set_header  X-Forwarded-For       $proxy_add_x_forwarded_for;
    proxy_set_header  X-Forwarded-Host      $server_name;

}

location /psmain/ {
  proxy_pass     http://zps.zps.svc.cluster.local/psmain/;
  include        conf.d/proxy_headers.inc;
  #proxy_set_header   X-Forwarded-For       $proxy_add_x_forwarded_for;
  #proxy_set_header   X-Forwarded-Proto     $scheme;
  #proxy_set_header   X-Forwarded-Host      $server_name;
  #proxy_set_header   X-Forwarded-Port      $server_port;
  #proxy_set_header   X-Forwarded-Prefix    /psmain;
}

location /ps-stand-spc-main/ {
  proxy_pass     http://ps-stand-spc-epm.zps.svc.cluster.local:8089/ps-stand-spc-main/;
  include        conf.d/proxy_headers.inc;
  #proxy_set_header   X-Forwarded-For       $proxy_add_x_forwarded_for;
  #proxy_set_header   X-Forwarded-Proto     $scheme;
  #proxy_set_header   X-Forwarded-Host      $server_name;
  #proxy_set_header   X-Forwarded-Port      $server_port;
  #proxy_set_header   X-Forwarded-Prefix    /ps-stand-spc-main;
}


## security

location /portalsettings/ {
  proxy_pass       http://portal-settings.frontend.svc.cluster.local:80/;
  include          conf.d/proxy_headers.inc;
}


location /security/ {
   proxy_pass http://security-settings.frontend.svc.cluster.local:8080/;
   include conf.d/proxy_headers.inc;
}

location /attributes-directory/ {
  proxy_pass       http://attributes-directory.frontend.svc.cluster.local:80/attributes-directory/;
  include          conf.d/proxy_headers.inc;
  add_header 'Access-Control-Allow-Origin' '*' always;
  add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, DELETE, PATCH, OPTIONS' always;
  add_header 'Access-Control-Allow-Headers' 'X-Requested-With, content-type, Authorization' always;
}

location /materiallot/ {
   proxy_pass http://material-lot.zps.svc.cluster.local:8080/materiallot/;
   include conf.d/proxy_headers.inc;
}

location /hostRootShell/json/ {
  proxy_pass     http://json-server.frontend.svc.cluster.local:80/;
  include        conf.d/proxy_headers.inc;
}

location /hostRootShell/ {
  proxy_pass       http://root-shell.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostTsds/ {
  proxy_pass       http://caa-tsds.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostNifi/ {
  proxy_pass       http://nifi-caa.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}
location /nifi-q-mon/ {
  proxy_pass       http://nifi-q-mon.nifi.svc.cluster.local:8000/;
  include conf.d/proxy_headers.inc;
}

location /hostDx/ {
  proxy_pass       http://document-explorer.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostDirectories/ {
  proxy_pass       http://caa-om.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostMnemo/ {
  proxy_pass       http://mnemo-editor.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /mnemo/ {
  proxy_pass       http://mnemo-editor.frontend.svc.cluster.local:80/mnemo/;
  include conf.d/proxy_headers.inc;
}

location /assets/ {
  proxy_pass       http://mnemo-editor.frontend.svc.cluster.local:80/assets/;
  include conf.d/proxy_headers.inc;
}

location /mnemos/api/ {
  proxy_pass       http://mnemoschemes-service.frontend.svc.cluster.local:80/mnemos/api/v1/;
  include conf.d/proxy_headers.inc;
}

location /hostNotifications/ {
  proxy_pass       http://notification-ui.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostEf/ {
  proxy_pass       http://ef-caa.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostCalculation/ {
   proxy_pass       http://calculation-caa.frontend.svc.cluster.local:80/;
   include conf.d/proxy_headers.inc;
 }

location /calcstore/ {
  proxy_pass     http://calcstore.frontend.svc.cluster.local:80/;
  include        conf.d/proxy_headers.inc;
}

location /hostReporteditor/ {
  proxy_pass       http://report-editor.frontend.svc.cluster.local:80/;
  include          conf.d/proxy_headers.inc;
}

location /reporting/ {
  proxy_pass       http://reporting.reporting.svc.cluster.local:80/;
  include          conf.d/proxy_headers.inc;
}

location /reporting/reporting-apidoc {
  proxy_pass       http://reporting.reporting.svc.cluster.local:80/reporting/reporting-apidoc;
  include          conf.d/proxy_headers.inc;
}

location /hostDi/ {
  proxy_pass       http://datainput.frontend.svc.cluster.local:80/;
  include          conf.d/proxy_headers.inc;
}

#location /hostMEB/ {
#  proxy_pass       http://meb-caa.frontend.svc.cluster.local:80/;
#  include          conf.d/proxy_headers.inc;
#}

##Udl

location /dfawebapi/ {
  proxy_pass     http://dfa-webapi.udl.svc.cluster.local:80/dfawebapi/;
  include        conf.d/proxy_headers.inc;
}

location /rtdwebapi/ {
  proxy_pass     http://rtd-webapi.udl.svc.cluster.local:80/rtdwebapi/;
  include        conf.d/proxy_headers.inc;
#  proxy_http_version 1.1;
#  proxy_set_header Upgrade $http_upgrade;
#  proxy_set_header Connection "upgrade";
}

location /mdswebapi/ {
  proxy_pass     http://mds-webapi.udl.svc.cluster.local:80/mdswebapi/;
  include        conf.d/proxy_headers.inc;
}

location /dsentitywebapi/ {
  proxy_pass     http://dsentity-webapi.udl.svc.cluster.local:80/dsentitywebapi/;
  include        conf.d/proxy_headers.inc;
}

##Event

location /event/ {
  proxy_pass       http://event.events.svc.cluster.local:80/event/;
  include          conf.d/proxy_headers.inc;
}

##CAmunda

#location /camunda/ {
#  proxy_pass http://camunda.zps.svc.claster.local:80/camunda/;
#  include conf.d/proxy_headers.inc;
#  add_header Content-Security-Policy "frame-ancestors 172.22.159.225";
#}
location /camunda/ {
  proxy_pass  http://camunda.zps.svc.cluster.local:80/camunda/;
  include conf.d/proxy_headers.inc;
  add_header 'Access-Control-Allow-Origin' '*' always;
  add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, DELETE, PATCH, OPTIONS' always;
  add_header 'Access-Control-Allow-Headers' 'X-Requested-With, content-type, Authorization' always;
  add_header Content-Security-Policy "frame-ancestors 172.22.159.225" always;
#   proxy_hide_header X-Frame-Options;
}

## TSDS

# TSDS-Subscription
location /subscription-apidoc {
  proxy_pass       http://subscription-service.tsds.svc.cluster.local:80/subscription-apidoc;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/Subscriptions {
  proxy_pass       http://subscription-service.tsds.svc.cluster.local:80/api/v0.1/Subscriptions;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/Exports {
  proxy_pass       http://subscription-service.tsds.svc.cluster.local:80/api/v0.1/Exports;
  include          conf.d/proxy_headers.inc;
}

# TSDS-Metadata
location /metadata-apidoc {
  proxy_pass       http://metadata-service.tsds.svc.cluster.local:80/metadata-apidoc;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/Dictionaries {
  proxy_pass       http://metadata-service.tsds.svc.cluster.local:80/api/v0.1/Dictionaries;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/Points {
  proxy_pass       http://metadata-service.tsds.svc.cluster.local:80/api/v0.1/Points;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/DefaultPointAttributes {
  proxy_pass       http://metadata-service.tsds.svc.cluster.local:80/api/v0.1/DefaultPointAttributes;
  include          conf.d/proxy_headers.inc;
}

# TSDS-Data
location /data-apidoc {
  proxy_pass       http://data-service.tsds.svc.cluster.local:80/data-apidoc;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/RawData {
  proxy_pass       http://data-service.tsds.svc.cluster.local:80/api/v0.1/RawData;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/ArcValue {
  proxy_pass       http://data-service.tsds.svc.cluster.local:80/api/v0.1/ArcValue;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/Plot {
  proxy_pass       http://data-service.tsds.svc.cluster.local:80/api/v0.1/Plot;
  include          conf.d/proxy_headers.inc;
}

location /api/v0.1/Summary {
  proxy_pass       http://data-service.tsds.svc.cluster.local:80/api/v0.1/Summary;
  include          conf.d/proxy_headers.inc;
}

# Object model

location /b2mml/ {
  proxy_pass     http://b2mml.object-model.svc.cluster.local:80/b2mml/;
  include        conf.d/proxy_headers.inc;
}

location /datareferences/ {
  proxy_pass     http://datareferences.object-model.svc.cluster.local:80/datareferences/;
  include        conf.d/proxy_headers.inc;
}

location /directories/ {
  proxy_pass     http://directories.object-model.svc.cluster.local:80/directories/;
  include        conf.d/proxy_headers.inc;
}

location /hostOM/ {
  proxy_pass     http://caa-om.frontend.svc.cluster.local:80/;
  include        conf.d/proxy_headers.inc;
}


location /object/ {
  proxy_pass     http://object.object-model.svc.cluster.local:80/object/;
  include        conf.d/proxy_headers.inc;
}

location /process/ {
  proxy_pass     http://process.object-model.svc.cluster.local:80/process/;
  include        conf.d/proxy_headers.inc;
}

location /properties/ {
  proxy_pass     http://properties.object-model.svc.cluster.local:80/properties/;
  include        conf.d/proxy_headers.inc;
}

location /propertydata/ {
  proxy_pass     http://propertydata.object-model.svc.cluster.local:80/propertydata/;
  include        conf.d/proxy_headers.inc;
}

location /testspecification/ {
  proxy_pass     http://testspecification.object-model.svc.cluster.local:80/testspecification/;
  include        conf.d/proxy_headers.inc;
}

location /uoms/ {
  proxy_pass     http://uoms.object-model.svc.cluster.local:80/uoms/;
  include        conf.d/proxy_headers.inc;
}

location /valuetypes/ {
  proxy_pass     http://valuetypes.object-model.svc.cluster.local:80/valuetypes/;
  include        conf.d/proxy_headers.inc;
}

location /hashtags/ {
  proxy_pass     http://hashtags.object-model.svc.cluster.local:80/hashtags/;
  include        conf.d/proxy_headers.inc;
}

location /graphql/ {
  proxy_pass     http://graphql.object-model.svc.cluster.local:80/graphql/;
  include        conf.d/proxy_headers.inc;
}

########new#####
location /propertiesview/ {
  proxy_pass     http://properties-view.object-model.svc.cluster.local:80/propertiesview/;
  include        conf.d/proxy_headers.inc;
}

location /operationdefinition/ {
  proxy_pass     http://sm-operationdefinition.object-model.svc.cluster.local:8080/operationdefinition/;
  include        conf.d/proxy_headers.inc;
}

location /operationperformance/ {
  proxy_pass     http://sm-operationperformance.object-model.svc.cluster.local:5000/operationperformance/;
  include        conf.d/proxy_headers.inc;
  #add_header 'Access-Control-Allow-Origin' '*' always;
  #add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, DELETE, PATCH, OPTIONS' always;
}

location /operationsschedule/ {
  proxy_pass     http://sm-operationsschedule.object-model.svc.cluster.local:5000/operationsschedule/;
  include        conf.d/proxy_headers.inc;
}

location /workdefinition/ {
  proxy_pass     http://sm-workdefinition.object-model.svc.cluster.local:5000/workdefinition/;
  include        conf.d/proxy_headers.inc;
}

location /workperformance/ {
  proxy_pass     http://sm-workperformance.object-model.svc.cluster.local:8080/workperformance/;
  include        conf.d/proxy_headers.inc;
}

location /smdirectories/ {
  proxy_pass     http://sm-directories.object-model.svc.cluster.local:5000/;
  include        conf.d/proxy_headers.inc;
 # proxy_set_header   X-Forwarded-For       $proxy_add_x_forwarded_for;
 # proxy_set_header   X-Forwarded-Proto     $scheme;
 # proxy_set_header   X-Forwarded-Host      $server_name;
 # proxy_set_header   X-Forwarded-Port      $server_port;
 # proxy_set_header   X-Forwarded-Prefix    /smdirectories;
}

location /workschedule/ {
  proxy_pass     http://sm-workschedule.object-model.svc.cluster.local:5000/workschedule/;
  include        conf.d/proxy_headers.inc;
}

# NiFi
location /nifi-api/ {
  proxy_pass       http://nifi.nifi.svc.cluster.local:8081/nifi-api/;
  include          conf.d/proxy_headers.inc;
  proxy_set_header X-ProxyScheme http;
  proxy_set_header X-ProxyHost $http_origin;
  proxy_set_header X-ProxyPort 80;
}

location /nifi-proxy/ {
  proxy_pass       http://nifi.nifi.svc.cluster.local:8081/;
  include          conf.d/proxy_headers.inc;
  proxy_set_header X-ProxyScheme http;
  proxy_set_header X-ProxyPort 80;
  proxy_set_header X-ProxyContextPath /nifi-proxy;
}

location /nifi-registry/ {
  proxy_pass	http://nifi-registry.nifi.svc.cluster.local:8080/nifi-registry/;
  include	conf.d/proxy_headers.inc;
}
location /nifi-registry-api/ {
  proxy_pass	http://nifi-registry.nifi.svc.cluster.local:8080/nifi-registry-api/;
  include	conf.d/proxy_headers.inc;
}
location /nifi-registry-docs/ {
  proxy_pass	http://nifi-registry.nifi.svc.cluster.local:8080/nifi-registry-docs/;
  include	conf.d/proxy_headers.inc;
}

# Spark
location /batches {
  proxy_pass       http://spark-m.spark.svc.cluster.local:8998/batches;
  include conf.d/proxy_headers.inc;
  if ($request_method = 'OPTIONS') {
    add_header 'Access-Control-Allow-Origin' '*';
    add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS, DELETE';
    add_header 'Access-Control-Allow-Headers' 'DNT,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type,Range';
    add_header 'Access-Control-Max-Age' 1728000;
    add_header 'Content-Type' 'text/plain; charset=utf-8';
    add_header 'Content-Length' 0;
    return 200;
  }
  proxy_set_header 'Access-Control-Allow-Origin' '*';
  add_header 'Access-Control-Allow-Origin' '*';
  add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS, DELETE';
  add_header 'Access-Control-Allow-Headers' 'DNT,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type,Range';
  add_header 'Access-Control-Expose-Headers' 'Content-Length,Content-Range';
}

location /spark-livy/ {
  proxy_pass       http://spark-m.spark.svc.cluster.local:8998/;
  include conf.d/proxy_headers.inc;
  add_header 'Access-Control-Allow-Origin' '*';
  add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS';
  add_header 'Access-Control-Allow-Headers' 'DNT,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type,Range';
  add_header 'Access-Control-Expose-Headers' 'Content-Length,Content-Range';
}
  
location /ui/ {
  proxy_pass       http://spark-m.spark.svc.cluster.local:8998/ui/;
  include conf.d/proxy_headers.inc;
  add_header 'Access-Control-Allow-Origin' '*';
  add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS';
  add_header 'Access-Control-Allow-Headers' 'DNT,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type,Range';
  add_header 'Access-Control-Expose-Headers' 'Content-Length,Content-Range';
}

location /static {
  proxy_pass       http://spark-m.spark.svc.cluster.local:8998/static;
  include conf.d/proxy_headers.inc;
  add_header 'Access-Control-Allow-Origin' '*';
  add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS';
  add_header 'Access-Control-Allow-Headers' 'DNT,User-Agent,X-Requested-With,If-Modified-Since,Cache-Control,Content-Type,Range';
  add_header 'Access-Control-Expose-Headers' 'Content-Length,Content-Range';
}

location /diagram/ {
    proxy_pass http://superset.superset.svc.cluster.local/superset/dashboard/1/;
	proxy_hide_header X-Frame-Options;
	add_header 'X-Frame-Options' 'ALLOW';
    #include conf.d/proxy_headers.inc;
  }

## EFK

# Kibana
location /kibana/ {
  proxy_pass       http://kibana-logging.efk.svc.cluster.local:5601/;
  include          conf.d/proxy_headers.inc;
}

location /hostPSWidgets/ {
  proxy_pass  http://zui-pkg-ps-widgets.frontend.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /envoy/ {
  proxy_pass  http://envoy.zqa.svc.cluster.local:9211/;
  include conf.d/proxy_headers.inc;
  proxy_http_version 1.1;
}

location /om2excel/ {
  proxy_pass  http://zif-om-om2excel.object-model.svc.cluster.local:80/;
  include conf.d/proxy_headers.inc;
}

location /hostPsMapConfig1cEpm {
  proxy_pass  http://zui-app-ps-map-config-1c-epm.zps.svc.cluster.local:8080/;
  include conf.d/proxy_headers.inc;
}
location /hostPsBom/ {
  proxy_pass     http://zui-app-ps-bom.frontend.svc.cluster.local:80/;
  include        conf.d/proxy_headers.inc;
}
location /mapping/ {
  proxy_pass     http://zif-mapping.object-model.svc.cluster.local/mapping/;
  include        conf.d/proxy_headers.inc;
}
location /hostReferencedDataMapping {
  proxy_pass     http://zui-app-referenced-data-mapping.frontend.svc.cluster.local/;
  include        conf.d/proxy_headers.inc;
}
location /zif-search/ {
  proxy_pass     http://zif-search.efk.svc.cluster.local/;
  include        conf.d/proxy_headers.inc;
}
location /hostMEB/ {
  proxy_pass     http://172.22.159.168:32757/;
  include        conf.d/proxy_headers.inc;
}

location /zqa-qms/ {
  proxy_pass     http://zqa-qms.zqa.svc.cluster.local:5001/;
  include        conf.d/proxy_headers.inc;
}
location /hostQms/ {
  proxy_pass     http://zui-app-qms.frontend.svc.cluster.local/;
  include        conf.d/proxy_headers.inc;
}
location /datamart/ {
  proxy_pass  http://ps-dx-datamart-epm.zps.svc.cluster.local:5000/;
  include conf.d/proxy_headers.inc;
}

