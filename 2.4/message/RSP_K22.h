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


#ifndef __RSP_K22__24_H__
#define __RSP_K22__24_H__

#include "../../common/Util.h"
#include "../segment/DSC.h"
#include "../segment/ERR.h"
#include "../segment/MSA.h"
#include "../segment/MSH.h"
#include "../segment/PD1.h"
#include "../segment/PID.h"
#include "../segment/QAK.h"
#include "../segment/QPD.h"
#include "../segment/QRI.h"

namespace HL7_24 {

/* Internal structures/groups */
struct RSP_K22_QUERY_RESPONSE; /* QUERY_RESPONSE */

/* QUERY_RESPONSE */
struct RSP_K22_QUERY_RESPONSE : public HL7Group {
  RSP_K22_QUERY_RESPONSE() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    RSP_K22_PID_10,
    RSP_K22_PD1_12,
    RSP_K22_QRI_15,
    FIELD_ID_MAX
  };

  const char* className() const { return "RSP_K22_QUERY_RESPONSE"; }
  RSP_K22_QUERY_RESPONSE* create() const {
    return new RSP_K22_QUERY_RESPONSE();
  }

 private:
  /* Initialize object */
  void init() {
    setName("RSP_K22.QUERY_RESPONSE");
    addObject<PID>(RSP_K22_PID_10, "PID.10", HL7::initialized,
		   HL7::repetition_off);
    addObject<PD1>(RSP_K22_PD1_12, "PD1.12", HL7::optional,
		   HL7::repetition_off);
    addObject<QRI>(RSP_K22_QRI_15, "QRI.15", HL7::optional,
		   HL7::repetition_off);
  }

 public:
  /* Getters list */
  PID* getPID_10(size_t index = 0) {
    return (PID*)this->getObjectSafe(index, RSP_K22_PID_10);
  }
  PD1* getPD1_12(size_t index = 0) {
    return (PD1*)this->getObjectSafe(index, RSP_K22_PD1_12);
  }
  QRI* getQRI_15(size_t index = 0) {
    return (QRI*)this->getObjectSafe(index, RSP_K22_QRI_15);
  }

  /* Checker list */
  bool isPID_10(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_PID_10) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isPD1_12(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_PD1_12) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isQRI_15(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_QRI_15) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RSP_K22_8 */

/* RSP_K22 */
struct RSP_K22 : public HL7Message {
  RSP_K22() { this->init(); }
  /* Fields ID  */
  enum FIELD_ID {
    RSP_K22_MSH_1,
    RSP_K22_MSA_2,
    RSP_K22_ERR_4,
    RSP_K22_QAK_6,
    RSP_K22_QPD_7,
    RSP_K22_QUERY_RESPONSE_8,
    RSP_K22_DSC_20,
    FIELD_ID_MAX
  };

  const char* className() const { return "RSP_K22"; }
  RSP_K22* create() const { return new RSP_K22(); }

  /* Initialize object */
  void init() {
    setName("RSP_K22");
    addObject<MSH>(RSP_K22_MSH_1, "MSH.1", HL7::initialized,
		   HL7::repetition_off);
    addObject<MSA>(RSP_K22_MSA_2, "MSA.2", HL7::initialized,
		   HL7::repetition_off);
    addObject<ERR>(RSP_K22_ERR_4, "ERR.4", HL7::optional, HL7::repetition_off);
    addObject<QAK>(RSP_K22_QAK_6, "QAK.6", HL7::initialized,
		   HL7::repetition_off);
    addObject<QPD>(RSP_K22_QPD_7, "QPD.7", HL7::initialized,
		   HL7::repetition_off);
    addObject<RSP_K22_QUERY_RESPONSE>(RSP_K22_QUERY_RESPONSE_8,
				      "RSP_K22.QUERY_RESPONSE", HL7::optional,
				      HL7::repetition_on);
    addObject<DSC>(RSP_K22_DSC_20, "DSC.20", HL7::optional,
		   HL7::repetition_off);
  }

  /* Getters list */
  MSH* getMSH_1(size_t index = 0) {
    return (MSH*)this->getObjectSafe(index, RSP_K22_MSH_1);
  }
  MSA* getMSA_2(size_t index = 0) {
    return (MSA*)this->getObjectSafe(index, RSP_K22_MSA_2);
  }
  ERR* getERR_4(size_t index = 0) {
    return (ERR*)this->getObjectSafe(index, RSP_K22_ERR_4);
  }
  QAK* getQAK_6(size_t index = 0) {
    return (QAK*)this->getObjectSafe(index, RSP_K22_QAK_6);
  }
  QPD* getQPD_7(size_t index = 0) {
    return (QPD*)this->getObjectSafe(index, RSP_K22_QPD_7);
  }
  RSP_K22_QUERY_RESPONSE* getQUERY_RESPONSE(size_t index = 0) {
    return (RSP_K22_QUERY_RESPONSE*)this->getObjectSafe(
	index, RSP_K22_QUERY_RESPONSE_8);
  }
  DSC* getDSC_20(size_t index = 0) {
    return (DSC*)this->getObjectSafe(index, RSP_K22_DSC_20);
  }

  /* Checker list */
  bool isMSH_1(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_MSH_1) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isMSA_2(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_MSA_2) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isERR_4(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_ERR_4) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isQAK_6(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_QAK_6) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isQPD_7(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_QPD_7) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isQUERY_RESPONSE(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_QUERY_RESPONSE_8) != NULL;
    } catch (...) {
    }
    return false;
  }
  bool isDSC_20(size_t index = 0) {
    try {
      return this->getObject(index, RSP_K22_DSC_20) != NULL;
    } catch (...) {
    }
    return false;
  }
}; /* RSP_K22_ */
} /* namespace HL7_24 */
#endif /*  __RSP_K22__24_H__ */
