#include <assert.h>
#include <iostream>
#include "Data.hpp"
#include "color.hpp"
#include "serialize.hpp"

using std::cout;

void testSerialization(Data* data) {
  cout << HYEL << *data << "\n" END;
  uintptr_t raw = serialize(data);
  cout << "  Serialized => " << raw << "\n" END;

  Data* ptr = deserialize(raw);
  cout << HCYN "  Deserialize => " << *data << "\n" END;

  assert(data == ptr);
  assert(data->country == ptr->country);
  assert(data->capital == ptr->capital);
  cout << HGRN "  Successful\n" END;
}

int main() {
  Data countries[] = {{"uk", "London"},
                      {"us", "Washington DC"},
                      {"kr", "Seoul"},
                      {"jp", "Tokyo"}};

  for (int i = 0; i < 4; i++)
    testSerialization(&countries[i]);
}