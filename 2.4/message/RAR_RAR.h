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


#ifndef __RAR_RAR__24_H__
#define __RAR_RAR__24_H__

#include "../../common/Util.h"
#include "../segment/DSC.h"
#include "../segment/ERR.h"
#include "../segment/MSA.h"
#include "../segment/MSH.h"
#include "../segment/NTE.h"
#include "../segment/ORC.h"
#include "../segment/PID.h"
#include "../segment/QRD.h"
#include "../segment/QRF.h"
#include "../segment/RXA.h"
#include "../segment/RXC.h"
#include "../segment/RXE.h"
#include "../segment/RXR.h"

namespace HL7_24 {

/* Internal structures/groups */
struct RAR_RAR_PATIENT;    /* PATIENT */
struct RAR_RAR_ENCODING;   /* ENCODING */
struct RAR_RAR_ORDER;      /* ORDER */
struct RAR_RAR_DEFINITION; /* DEFINITION */

/* PATIENT */
struct RAR_RAR_PATIENT : public HL7Group {
  RAR_RAR_PATIENT() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID { RAR_RAR_PID_12, RAR_RAR_NTE_15, FIELD_ID_MAX };

  const char* className() const { return "RAR_RAR_PATIENT"; }
  RAR_RAR_PATIENT* create() const { return new RAR_RAR_PATIENT(); }

 private:
  /* Initialize object */
  void init() {
    setName("RAR_RAR.PATIENT");
    addObject<PID>(RAR_RAR_PID_12, "PID.12", HL7::initialized,
		   HL7::repetition_off);
    addObject<NTE>(RAR_RAR_NTE_15, "NTE.15", HL7::optional, HL7::repetition_on);
  }

 public:
  /* Getters list */
  PID* getPID_12(size_t index = 0) {
    return (PID*)this->getObjectSafe(index, RAR_RAR_PID_12);
  }
  NTE* getNTE_15(size_t index = 0) {
    return (NTE*)this->getObjectSafe(index, RAR_RAR_NTE_15);
  }

  /* Checker list */
  bool isPID_12(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_PID_12) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isNTE_15(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_NTE_15) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RAR_RAR_11 */

/* ENCODING */
struct RAR_RAR_ENCODING : public HL7Group {
  RAR_RAR_ENCODING() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    RAR_RAR_RXE_22,
    RAR_RAR_RXR_24,
    RAR_RAR_RXC_28,
    FIELD_ID_MAX
  };

  const char* className() const { return "RAR_RAR_ENCODING"; }
  RAR_RAR_ENCODING* create() const { return new RAR_RAR_ENCODING(); }

  /* Initialize object */
  void init() {
    setName("RAR_RAR.ENCODING");
    addObject<RXE>(RAR_RAR_RXE_22, "RXE.22", HL7::initialized,
		   HL7::repetition_off);
    addObject<RXR>(RAR_RAR_RXR_24, "RXR.24", HL7::initialized,
		   HL7::repetition_on);
    addObject<RXC>(RAR_RAR_RXC_28, "RXC.28", HL7::optional, HL7::repetition_on);
  }

  /* Getters list */
  RXE* getRXE_22(size_t index = 0) {
    return (RXE*)this->getObjectSafe(index, RAR_RAR_RXE_22);
  }
  RXR* getRXR_24(size_t index = 0) {
    return (RXR*)this->getObjectSafe(index, RAR_RAR_RXR_24);
  }
  RXC* getRXC_28(size_t index = 0) {
    return (RXC*)this->getObjectSafe(index, RAR_RAR_RXC_28);
  }

  /* Checker list */
  bool isRXE_22(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_RXE_22) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isRXR_24(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_RXR_24) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isRXC_28(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_RXC_28) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RAR_RAR_21 */

/* ORDER */
struct RAR_RAR_ORDER : public HL7Group {
  RAR_RAR_ORDER() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    RAR_RAR_ORC_20,
    RAR_RAR_ENCODING_21,
    RAR_RAR_RXA_33,
    RAR_RAR_RXR_35,
    FIELD_ID_MAX
  };

  const char* className() const { return "RAR_RAR_ORDER"; }
  RAR_RAR_ORDER* create() const { return new RAR_RAR_ORDER(); }

  /* Initialize object */
  void init() {
    setName("RAR_RAR.ORDER");
    addObject<ORC>(RAR_RAR_ORC_20, "ORC.20", HL7::initialized,
		   HL7::repetition_off);
    addObject<RAR_RAR_ENCODING>(RAR_RAR_ENCODING_21, "RAR_RAR.ENCODING",
				HL7::optional, HL7::repetition_off);
    addObject<RXA>(RAR_RAR_RXA_33, "RXA.33", HL7::initialized,
		   HL7::repetition_on);
    addObject<RXR>(RAR_RAR_RXR_35, "RXR.35", HL7::initialized,
		   HL7::repetition_off);
  }

  /* Getters list */
  ORC* getORC_20(size_t index = 0) {
    return (ORC*)this->getObjectSafe(index, RAR_RAR_ORC_20);
  }
  RAR_RAR_ENCODING* getENCODING(size_t index = 0) {
    return (RAR_RAR_ENCODING*)this->getObjectSafe(index, RAR_RAR_ENCODING_21);
  }
  RXA* getRXA_33(size_t index = 0) {
    return (RXA*)this->getObjectSafe(index, RAR_RAR_RXA_33);
  }
  RXR* getRXR_35(size_t index = 0) {
    return (RXR*)this->getObjectSafe(index, RAR_RAR_RXR_35);
  }

  /* Checker list */
  bool isORC_20(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_ORC_20) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isENCODING(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_ENCODING_21) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isRXA_33(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_RXA_33) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isRXR_35(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_RXR_35) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RAR_RAR_19 */

/* DEFINITION */
struct RAR_RAR_DEFINITION : public HL7Group {
  RAR_RAR_DEFINITION() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    RAR_RAR_QRD_7,
    RAR_RAR_QRF_9,
    RAR_RAR_PATIENT_11,
    RAR_RAR_ORDER_19,
    FIELD_ID_MAX
  };

  const char* className() const { return "RAR_RAR_DEFINITION"; }
  RAR_RAR_DEFINITION* create() const { return new RAR_RAR_DEFINITION(); }

  /* Initialize object */
  void init() {
    setName("RAR_RAR.DEFINITION");
    addObject<QRD>(RAR_RAR_QRD_7, "QRD.7", HL7::initialized,
		   HL7::repetition_off);
    addObject<QRF>(RAR_RAR_QRF_9, "QRF.9", HL7::optional, HL7::repetition_off);
    addObject<RAR_RAR_PATIENT>(RAR_RAR_PATIENT_11, "RAR_RAR.PATIENT",
			       HL7::optional, HL7::repetition_off);
    addObject<RAR_RAR_ORDER>(RAR_RAR_ORDER_19, "RAR_RAR.ORDER",
			     HL7::initialized, HL7::repetition_on);
  }

  /* Getters list */
  QRD* getQRD_7(size_t index = 0) {
    return (QRD*)this->getObjectSafe(index, RAR_RAR_QRD_7);
  }
  QRF* getQRF_9(size_t index = 0) {
    return (QRF*)this->getObjectSafe(index, RAR_RAR_QRF_9);
  }
  RAR_RAR_PATIENT* getPATIENT(size_t index = 0) {
    return (RAR_RAR_PATIENT*)this->getObjectSafe(index, RAR_RAR_PATIENT_11);
  }
  RAR_RAR_ORDER* getORDER(size_t index = 0) {
    return (RAR_RAR_ORDER*)this->getObjectSafe(index, RAR_RAR_ORDER_19);
  }

  /* Checker list */
  bool isQRD_7(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_QRD_7) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isQRF_9(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_QRF_9) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isPATIENT(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_PATIENT_11) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isORDER(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_ORDER_19) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RAR_RAR_6 */

/* RAR_RAR */
struct RAR_RAR : public HL7Message {
  RAR_RAR() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    RAR_RAR_MSH_1,
    RAR_RAR_MSA_2,
    RAR_RAR_ERR_4,
    RAR_RAR_DEFINITION_6,
    RAR_RAR_DSC_39,
    FIELD_ID_MAX
  };

  const char* className() const { return "RAR_RAR"; }
  RAR_RAR* create() const { return new RAR_RAR(); }

  /* Initialize object */
  void init() {
    setName("RAR_RAR");
    addObject<MSH>(RAR_RAR_MSH_1, "MSH.1", HL7::initialized,
		   HL7::repetition_off);
    addObject<MSA>(RAR_RAR_MSA_2, "MSA.2", HL7::initialized,
		   HL7::repetition_off);
    addObject<ERR>(RAR_RAR_ERR_4, "ERR.4", HL7::optional, HL7::repetition_off);
    addObject<RAR_RAR_DEFINITION>(RAR_RAR_DEFINITION_6, "RAR_RAR.DEFINITION",
				  HL7::initialized, HL7::repetition_on);
    addObject<DSC>(RAR_RAR_DSC_39, "DSC.39", HL7::optional,
		   HL7::repetition_off);
  }

  /* Getters list */
  MSH* getMSH_1(size_t index = 0) {
    return (MSH*)this->getObjectSafe(index, RAR_RAR_MSH_1);
  }
  MSA* getMSA_2(size_t index = 0) {
    return (MSA*)this->getObjectSafe(index, RAR_RAR_MSA_2);
  }
  ERR* getERR_4(size_t index = 0) {
    return (ERR*)this->getObjectSafe(index, RAR_RAR_ERR_4);
  }
  RAR_RAR_DEFINITION* getDEFINITION(size_t index = 0) {
    return (RAR_RAR_DEFINITION*)this->getObjectSafe(index,
						    RAR_RAR_DEFINITION_6);
  }
  DSC* getDSC_39(size_t index = 0) {
    return (DSC*)this->getObjectSafe(index, RAR_RAR_DSC_39);
  }

  /* Checker list */
  bool isMSH_1(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_MSH_1) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isMSA_2(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_MSA_2) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isERR_4(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_ERR_4) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isDEFINITION(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_DEFINITION_6) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isDSC_39(size_t index = 0) {
    try {
      return this->getObject(index, RAR_RAR_DSC_39) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RAR_RAR_ */
} /* namespace HL7_24 */
#endif /*  __RAR_RAR__24_H__ */
