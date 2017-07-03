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


#ifndef __ADT_A16__24_H__
#define __ADT_A16__24_H__

#include "../../common/Util.h"
#include "../segment/DB1.h"
#include "../segment/DG1.h"
#include "../segment/DRG.h"
#include "../segment/EVN.h"
#include "../segment/MSH.h"
#include "../segment/OBX.h"
#include "../segment/PD1.h"
#include "../segment/PID.h"
#include "../segment/PV1.h"
#include "../segment/PV2.h"
#include "../segment/ROL.h"

namespace HL7_24 {

/* ADT_A16 */
struct ADT_A16 : public HL7Message {
  ADT_A16() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    ADT_A16_MSH_1,
    ADT_A16_EVN_2,
    ADT_A16_PID_3,
    ADT_A16_PD1_5,
    ADT_A16_ROL_9,
    ADT_A16_PV1_12,
    ADT_A16_PV2_14,
    ADT_A16_ROL_18,
    ADT_A16_DB1_23,
    ADT_A16_OBX_28,
    ADT_A16_DG1_33,
    ADT_A16_DRG_37,
    FIELD_ID_MAX
  };

  const char* className() const { return "ADT_A16"; }
  ADT_A16* create() const { return new ADT_A16(); }

 private:
  /* Initialize object */
  void init() {
    setName("ADT_A16");
    addObject<MSH>(ADT_A16_MSH_1, "MSH.1", HL7::initialized,
		   HL7::repetition_off);
    addObject<EVN>(ADT_A16_EVN_2, "EVN.2", HL7::initialized,
		   HL7::repetition_off);
    addObject<PID>(ADT_A16_PID_3, "PID.3", HL7::initialized,
		   HL7::repetition_off);
    addObject<PD1>(ADT_A16_PD1_5, "PD1.5", HL7::optional, HL7::repetition_off);
    addObject<ROL>(ADT_A16_ROL_9, "ROL.9", HL7::optional, HL7::repetition_on);
    addObject<PV1>(ADT_A16_PV1_12, "PV1.12", HL7::initialized,
		   HL7::repetition_off);
    addObject<PV2>(ADT_A16_PV2_14, "PV2.14", HL7::optional,
		   HL7::repetition_off);
    addObject<ROL>(ADT_A16_ROL_18, "ROL.18", HL7::optional, HL7::repetition_on);
    addObject<DB1>(ADT_A16_DB1_23, "DB1.23", HL7::optional, HL7::repetition_on);
    addObject<OBX>(ADT_A16_OBX_28, "OBX.28", HL7::optional, HL7::repetition_on);
    addObject<DG1>(ADT_A16_DG1_33, "DG1.33", HL7::optional, HL7::repetition_on);
    addObject<DRG>(ADT_A16_DRG_37, "DRG.37", HL7::optional,
		   HL7::repetition_off);
  }

 public:
  /* Getters list */
  MSH* getMSH_1(size_t index = 0) {
    return (MSH*)this->getObjectSafe(index, ADT_A16_MSH_1);
  }
  EVN* getEVN_2(size_t index = 0) {
    return (EVN*)this->getObjectSafe(index, ADT_A16_EVN_2);
  }
  PID* getPID_3(size_t index = 0) {
    return (PID*)this->getObjectSafe(index, ADT_A16_PID_3);
  }
  PD1* getPD1_5(size_t index = 0) {
    return (PD1*)this->getObjectSafe(index, ADT_A16_PD1_5);
  }
  ROL* getROL_9(size_t index = 0) {
    return (ROL*)this->getObjectSafe(index, ADT_A16_ROL_9);
  }
  PV1* getPV1_12(size_t index = 0) {
    return (PV1*)this->getObjectSafe(index, ADT_A16_PV1_12);
  }
  PV2* getPV2_14(size_t index = 0) {
    return (PV2*)this->getObjectSafe(index, ADT_A16_PV2_14);
  }
  ROL* getROL_18(size_t index = 0) {
    return (ROL*)this->getObjectSafe(index, ADT_A16_ROL_18);
  }
  DB1* getDB1_23(size_t index = 0) {
    return (DB1*)this->getObjectSafe(index, ADT_A16_DB1_23);
  }
  OBX* getOBX_28(size_t index = 0) {
    return (OBX*)this->getObjectSafe(index, ADT_A16_OBX_28);
  }
  DG1* getDG1_33(size_t index = 0) {
    return (DG1*)this->getObjectSafe(index, ADT_A16_DG1_33);
  }
  DRG* getDRG_37(size_t index = 0) {
    return (DRG*)this->getObjectSafe(index, ADT_A16_DRG_37);
  }

  /* Checker list */
  bool isMSH_1(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_MSH_1) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isEVN_2(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_EVN_2) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isPID_3(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_PID_3) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isPD1_5(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_PD1_5) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isROL_9(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_ROL_9) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isPV1_12(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_PV1_12) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isPV2_14(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_PV2_14) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isROL_18(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_ROL_18) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isDB1_23(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_DB1_23) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isOBX_28(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_OBX_28) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isDG1_33(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_DG1_33) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isDRG_37(size_t index = 0) {
    try {
      return this->getObject(index, ADT_A16_DRG_37) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* ADT_A16_ */
} /* namespace HL7_24 */
#endif /*  __ADT_A16__24_H__ */
