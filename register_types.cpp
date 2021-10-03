#include "register_types.h"
#include "areaprober.h"
#include "core/class_db.h"
#include "core/engine.h"
void register_areaprober_types(){
  ClassDB::register_class<AreaProber>();
}

void unregister_areaprober_types(/* arguments */) {
  /* nothing to do here */
}
