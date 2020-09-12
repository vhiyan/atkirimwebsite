bool timer(unsigned int id,unsigned long microdetik)
{
  currentTimeWifi[id] = micros();
  if(currentTimeWifi[id]-previousTimeWifi[id]>=microdetik)
  {
    previousTimeWifi[id] = micros();
    return true;
  }
  else 
    return false;
}
//
//bool jeda(bool initial,unsigned long microdetik)
//{
//  if(initial){currentTimeWifi = micros();}
//  else 
//    {
//        if(currentTimeWifi-previousTimeWifi>=microdetik)
//       {
//        previousTimeWifi = micros();
//        return true;
//        }
//        else 
//        return false;
//    }
//}
