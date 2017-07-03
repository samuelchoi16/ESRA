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


#ifndef __FHS_v24_H__
#define __FHS_v24_H__

#include "../../common/Util.h"
#include "../datatype/ST.h"
#include "../datatype/TS.h"

namespace HL7_24 {

/* File Header */
class FHS : public HL7Segment {
 public:
  FHS() { this->init(); }

 private:
  /* */
  enum FIELD_ID {
    FHS_1,
    FHS_2,
    FHS_3,
    FHS_4,
    FHS_5,
    FHS_6,
    FHS_7,
    FHS_8,
    FHS_9,
    FHS_10,
    FHS_11,
    FHS_12,
    FIELD_ID_MAX
  };

 public:
  const char* className() const { return "FHS"; }
  FHS* create() const { return new FHS(); }

 private:
  void init() {
    setName("FHS");
    /* Init members */
    addObject<ST>(FHS_1, "FHS.1", HL7::initialized, HL7::repetition_off);
    addObject<ST>(FHS_2, "FHS.2", HL7::initialized, HL7::repetition_off);
    addObject<ST>(FHS_3, "FHS.3", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_4, "FHS.4", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_5, "FHS.5", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_6, "FHS.6", HL7::optional, HL7::repetition_off);
    addObject<TS>(FHS_7, "FHS.7", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_8, "FHS.8", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_9, "FHS.9", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_10, "FHS.10", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_11, "FHS.11", HL7::optional, HL7::repetition_off);
    addObject<ST>(FHS_12, "FHS.12", HL7::optional, HL7::repetition_off);
  }

 public:
  /* Getters */
  /****************************************
   * File Field Separator
   */

  ST* getFHS_1(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_1);
  }

  ST* getFileFieldSeparator(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_1);
  }

  bool isFHS_1(size_t index = 0) {
    try {
      return this->getObject(index, FHS_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileFieldSeparator(size_t index = 0) {
    try {
      return this->getObject(index, FHS_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Encoding Characters
   */

  ST* getFHS_2(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_2);
  }

  ST* getFileEncodingCharacters(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_2);
  }

  bool isFHS_2(size_t index = 0) {
    try {
      return this->getObject(index, FHS_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileEncodingCharacters(size_t index = 0) {
    try {
      return this->getObject(index, FHS_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Sending Application
   */

  ST* getFHS_3(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_3);
  }

  ST* getFileSendingApplication(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_3);
  }

  bool isFHS_3(size_t index = 0) {
    try {
      return this->getObject(index, FHS_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileSendingApplication(size_t index = 0) {
    try {
      return this->getObject(index, FHS_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Sending Facility
   */

  ST* getFHS_4(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_4);
  }

  ST* getFileSendingFacility(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_4);
  }

  bool isFHS_4(size_t index = 0) {
    try {
      return this->getObject(index, FHS_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileSendingFacility(size_t index = 0) {
    try {
      return this->getObject(index, FHS_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Receiving Application
   */

  ST* getFHS_5(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_5);
  }

  ST* getFileReceivingApplication(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_5);
  }

  bool isFHS_5(size_t index = 0) {
    try {
      return this->getObject(index, FHS_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileReceivingApplication(size_t index = 0) {
    try {
      return this->getObject(index, FHS_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Receiving Facility
   */

  ST* getFHS_6(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_6);
  }

  ST* getFileReceivingFacility(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_6);
  }

  bool isFHS_6(size_t index = 0) {
    try {
      return this->getObject(index, FHS_6) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileReceivingFacility(size_t index = 0) {
    try {
      return this->getObject(index, FHS_6) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Creation Date/Time
   */

  TS* getFHS_7(size_t index = 0) {
    return (TS*)this->getObjectSafe(index, FHS_7);
  }

  TS* getFileCreationDateTime(size_t index = 0) {
    return (TS*)this->getObjectSafe(index, FHS_7);
  }

  bool isFHS_7(size_t index = 0) {
    try {
      return this->getObject(index, FHS_7) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileCreationDateTime(size_t index = 0) {
    try {
      return this->getObject(index, FHS_7) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Security
   */

  ST* getFHS_8(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_8);
  }

  ST* getFileSecurity(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_8);
  }

  bool isFHS_8(size_t index = 0) {
    try {
      return this->getObject(index, FHS_8) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileSecurity(size_t index = 0) {
    try {
      return this->getObject(index, FHS_8) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Name/ID
   */

  ST* getFHS_9(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_9);
  }

  ST* getFileNameID(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_9);
  }

  bool isFHS_9(size_t index = 0) {
    try {
      return this->getObject(index, FHS_9) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileNameID(size_t index = 0) {
    try {
      return this->getObject(index, FHS_9) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Header Comment
   */

  ST* getFHS_10(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_10);
  }

  ST* getFileHeaderComment(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_10);
  }

  bool isFHS_10(size_t index = 0) {
    try {
      return this->getObject(index, FHS_10) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileHeaderComment(size_t index = 0) {
    try {
      return this->getObject(index, FHS_10) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * File Control ID
   */

  ST* getFHS_11(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_11);
  }

  ST* getFileControlID(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_11);
  }

  bool isFHS_11(size_t index = 0) {
    try {
      return this->getObject(index, FHS_11) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isFileControlID(size_t index = 0) {
    try {
      return this->getObject(index, FHS_11) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * Reference File Control ID
   */

  ST* getFHS_12(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_12);
  }

  ST* getReferenceFileControlID(size_t index = 0) {
    return (ST*)this->getObjectSafe(index, FHS_12);
  }

  bool isFHS_12(size_t index = 0) {
    try {
      return this->getObject(index, FHS_12) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isReferenceFileControlID(size_t index = 0) {
    try {
      return this->getObject(index, FHS_12) != NULL;
    } catch (...) {
    }
    return false;
  }

}; /* End of FHS */

} /* End of namespace HL7_24 */
#endif /* __FHS_v24_H__ */
