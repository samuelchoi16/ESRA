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


#ifndef __MRG_v24_H__
#define __MRG_v24_H__

#include "../../common/Util.h"
#include "../datatype/CX.h"
#include "../datatype/XPN.h"

namespace HL7_24 {

/* Merge patient information */
class MRG : public HL7Segment {
 public:
  MRG() { this->init(); }

 private:
  /* */
  enum FIELD_ID {
    MRG_1,
    MRG_2,
    MRG_3,
    MRG_4,
    MRG_5,
    MRG_6,
    MRG_7,
    FIELD_ID_MAX
  };

 public:
  const char* className() const { return "MRG"; }
  MRG* create() const { return new MRG(); }

 private:
  void init() {
    setName("MRG");
    /* Init members */
    addObject<CX>(MRG_1, "MRG.1", HL7::initialized, HL7::repetition_on);
    addObject<CX>(MRG_2, "MRG.2", HL7::optional, HL7::repetition_on);
    addObject<CX>(MRG_3, "MRG.3", HL7::optional, HL7::repetition_off);
    addObject<CX>(MRG_4, "MRG.4", HL7::optional, HL7::repetition_off);
    addObject<CX>(MRG_5, "MRG.5", HL7::optional, HL7::repetition_off);
    addObject<CX>(MRG_6, "MRG.6", HL7::optional, HL7::repetition_off);
    addObject<XPN>(MRG_7, "MRG.7", HL7::optional, HL7::repetition_on);
  }

 public:
  /* Getters */
  /****************************************
   * Prior Patient Identifier List
   */

  CX* getMRG_1(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_1);
  }

  CX* getPriorPatientIdentifierList(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_1);
  }

  bool isMRG_1(size_t index = 0) {
    try {
      return this->getObject(index, MRG_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorPatientIdentifierList(size_t index = 0) {
    try {
      return this->getObject(index, MRG_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Prior Alternate Patient ID
   */

  CX* getMRG_2(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_2);
  }

  CX* getPriorAlternatePatientID(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_2);
  }

  bool isMRG_2(size_t index = 0) {
    try {
      return this->getObject(index, MRG_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorAlternatePatientID(size_t index = 0) {
    try {
      return this->getObject(index, MRG_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Prior Patient Account Number
   */

  CX* getMRG_3(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_3);
  }

  CX* getPriorPatientAccountNumber(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_3);
  }

  bool isMRG_3(size_t index = 0) {
    try {
      return this->getObject(index, MRG_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorPatientAccountNumber(size_t index = 0) {
    try {
      return this->getObject(index, MRG_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Prior Patient ID
   */

  CX* getMRG_4(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_4);
  }

  CX* getPriorPatientID(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_4);
  }

  bool isMRG_4(size_t index = 0) {
    try {
      return this->getObject(index, MRG_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorPatientID(size_t index = 0) {
    try {
      return this->getObject(index, MRG_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Prior Visit Number
   */

  CX* getMRG_5(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_5);
  }

  CX* getPriorVisitNumber(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_5);
  }

  bool isMRG_5(size_t index = 0) {
    try {
      return this->getObject(index, MRG_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorVisitNumber(size_t index = 0) {
    try {
      return this->getObject(index, MRG_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Prior Alternate Visit ID
   */

  CX* getMRG_6(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_6);
  }

  CX* getPriorAlternateVisitID(size_t index = 0) {
    return (CX*)this->getObjectSafe(index, MRG_6);
  }

  bool isMRG_6(size_t index = 0) {
    try {
      return this->getObject(index, MRG_6) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorAlternateVisitID(size_t index = 0) {
    try {
      return this->getObject(index, MRG_6) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Prior Patient Name
   */

  XPN* getMRG_7(size_t index = 0) {
    return (XPN*)this->getObjectSafe(index, MRG_7);
  }

  XPN* getPriorPatientName(size_t index = 0) {
    return (XPN*)this->getObjectSafe(index, MRG_7);
  }

  bool isMRG_7(size_t index = 0) {
    try {
      return this->getObject(index, MRG_7) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isPriorPatientName(size_t index = 0) {
    try {
      return this->getObject(index, MRG_7) != NULL;
    } catch (...) {
    }
    return false;
  }

}; /* End of MRG */

} /* End of namespace HL7_24 */
#endif /* __MRG_v24_H__ */
