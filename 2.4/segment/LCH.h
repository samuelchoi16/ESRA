/*
 * This file is part of Auriga HL7 library.
 *
 * Auriga HL7 library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Auriga HL7 library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Auriga HL7 library.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __LCH_v24_H__
#define __LCH_v24_H__

#include "../../common/Util.h"
#include "../datatype/CE_0136.h"
#include "../datatype/CE_0324.h"
#include "../datatype/EI.h"
#include "../datatype/ID.h"
#include "../datatype/PL.h"

namespace HL7_24 {

/* Location Characteristic */
class LCH : public HL7Segment {
 public:
  LCH() { this->init(); }

 private:
  /* */
  enum FIELD_ID { LCH_1, LCH_2, LCH_3, LCH_4, LCH_5, FIELD_ID_MAX };

 public:
  const char* className() const { return "LCH"; }
  LCH* create() const { return new LCH(); }

 private:
  void init() {
    setName("LCH");
    /* Init members */
    addObject<PL>(LCH_1, "LCH.1", HL7::initialized, HL7::repetition_off);
    addObject<ID>(LCH_2, "LCH.2", HL7::optional, HL7::repetition_off);
    addObject<EI>(LCH_3, "LCH.3", HL7::optional, HL7::repetition_off);
    addObject<CE_0324>(LCH_4, "LCH.4", HL7::initialized, HL7::repetition_off);
    addObject<CE_0136>(LCH_5, "LCH.5", HL7::initialized, HL7::repetition_off);
  }

 public:
  /* Getters */
  /****************************************
   * Primary Key Value - LCH
   */

  PL* getLCH_1(size_t index = 0) {
    return (PL*)this->getObjectSafe(index, LCH_1);
  }

  PL* getPrimaryKeyValueLCH(size_t index = 0) {
    return (PL*)this->getObjectSafe(index, LCH_1);
  }

  bool isLCH_1(size_t index = 0) {
    try {
      return this->getObject(index, LCH_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPrimaryKeyValueLCH(size_t index = 0) {
    try {
      return this->getObject(index, LCH_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Segment Action Code
   */

  ID* getLCH_2(size_t index = 0) {
    return (ID*)this->getObjectSafe(index, LCH_2);
  }

  ID* getSegmentActionCode(size_t index = 0) {
    return (ID*)this->getObjectSafe(index, LCH_2);
  }

  bool isLCH_2(size_t index = 0) {
    try {
      return this->getObject(index, LCH_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isSegmentActionCode(size_t index = 0) {
    try {
      return this->getObject(index, LCH_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Segment Unique Key
   */

  EI* getLCH_3(size_t index = 0) {
    return (EI*)this->getObjectSafe(index, LCH_3);
  }

  EI* getSegmentUniqueKey(size_t index = 0) {
    return (EI*)this->getObjectSafe(index, LCH_3);
  }

  bool isLCH_3(size_t index = 0) {
    try {
      return this->getObject(index, LCH_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isSegmentUniqueKey(size_t index = 0) {
    try {
      return this->getObject(index, LCH_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Location Characteristic ID
   */

  CE_0324* getLCH_4(size_t index = 0) {
    return (CE_0324*)this->getObjectSafe(index, LCH_4);
  }

  CE_0324* getLocationCharacteristicID(size_t index = 0) {
    return (CE_0324*)this->getObjectSafe(index, LCH_4);
  }

  bool isLCH_4(size_t index = 0) {
    try {
      return this->getObject(index, LCH_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isLocationCharacteristicID(size_t index = 0) {
    try {
      return this->getObject(index, LCH_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Location Characteristic Value-LCH
   */

  CE_0136* getLCH_5(size_t index = 0) {
    return (CE_0136*)this->getObjectSafe(index, LCH_5);
  }

  CE_0136* getLocationCharacteristicValueLCH(size_t index = 0) {
    return (CE_0136*)this->getObjectSafe(index, LCH_5);
  }

  bool isLCH_5(size_t index = 0) {
    try {
      return this->getObject(index, LCH_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isLocationCharacteristicValueLCH(size_t index = 0) {
    try {
      return this->getObject(index, LCH_5) != NULL;
    } catch (...) {
    }
    return false;
  }

}; /* End of LCH */

} /* End of namespace HL7_24 */
#endif /* __LCH_v24_H__ */
