#include "Serializer.h"

int main(){

  Data* data = new Data();
  data->age = 1;
  data->lastName = "leBernard";
  data->name = "Bill";
  uintptr_t serialized = Serializer::serialize(data);
  Data* deserialized = Serializer::deserialize(serialized);
  std::cout << data->age << " = " << deserialized->age << std::endl;
  std::cout << data->name << " = " << deserialized->name << std::endl;
  std::cout << data->lastName << " = " << deserialized->lastName << std::endl;
return 1;
}