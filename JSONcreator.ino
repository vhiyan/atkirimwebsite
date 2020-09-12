
char *listSensor[11] = {
"air_temperature",
"air_humidity",
"air_pressure",
"rain_gauge",
"wind_speed",
"wind_direction",
"soil_temp",
"soil_moist",
"soil_ph",
"soil_EC"};

char *listUnit[11] = {
"Celcius",
"% RH",
"hPa",
"mm/min",
"m/s",
"derajat",
"Celcius",
"%",
"ph",
"mS/cm"};



String bodyJSON(float at, float ah, float ap, float rg, float ws, int wd,float st,float sm,float sp,float se)
{

    String hasilJSON;
    StaticJsonDocument<1100> doc;
    
    doc[F("version")] = F("PR-alpha.0.1");
    doc[F("node_id")] = "3425345234";
    doc[F("time")] = "2020-09-11 11:36:23";
    // JsonArray& item = root.createNestedArray("item");
    
    for (int i = 0; i < 10; i++)
    {  
        StaticJsonDocument<100> sensorJSON;
        sensorJSON[F("sensor_type")] = listSensor[i];
        sensorJSON[F("scale")] = listUnit[i];\
        switch (i)
        {
        case 0:sensorJSON[F("value")] = at;break;
        case 1:sensorJSON[F("value")] = ah;break;
        case 2:sensorJSON[F("value")] = ap;break;
        case 3:sensorJSON[F("value")] = rg;break;
        case 4:sensorJSON[F("value")] = ws;break;
        case 5:sensorJSON[F("value")] = wd;break;
        case 6:sensorJSON[F("value")] = st;break;
        case 7:sensorJSON[F("value")] = sm;break;
        case 8:sensorJSON[F("value")] = sp;break;
        case 9:sensorJSON[F("value")] = se;break;      
        default:
            break;
        }
        
        doc[F("item")].add(sensorJSON);
    }

    doc[F("checksumkey")]="ASFDFJKL4857293845729834AX==";

    serializeJson(doc, hasilJSON);
    return hasilJSON; 
}

String createHeader(String hst, int cnt)
{
    return "POST / HTTP/1.1\r\nHost:" + hst + "\r\nContent-Type: application/json\r\ncontent-length:" + cnt + "\r\n\r\n" ;
}