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


#ifndef __CE_0162_v24_H__
#define __CE_0162_v24_H__

#include "../../common/Util.h"
#include "../datatype/IS.h"
#include "../datatype/ST.h"

namespace HL7_24 {

/*  */
class CE_0162 : public HL7Data {
 public:
  CE_0162() { this->init(); }

 private:
  /* Field ID */
  enum FIELD_ID {
    CE_0162_1, /* identifier (ST) */
    CE_0162_2, /* text */
    CE_0162_3, /* name of coding system */
    CE_0162_4, /* alternate identifier (ST) */
    CE_0162_5, /* alternate text */
    CE_0162_6, /* name of alternate coding system */
    FIELD_ID_MAX
  };

 public:
  const char *className() const { return "CE_0162"; }
  CE_0162 *create() const { return new CE_0162(); }

 private:
  void init() {
    // setName("CE_0162");
    /* Init members */
    addObject<ST>(CE_0162_1, "CE_0162.1", HL7::initialized,
		  HL7::repetition_off);
    addParams(CE_0162_1, "AP");  /* Apply Externally */
    addParams(CE_0162_1, "B");   /* Buccal */
    addParams(CE_0162_1, "DT");  /* Dental */
    addParams(CE_0162_1, "EP");  /* Epidural */
    addParams(CE_0162_1, "ET");  /* Endotrachial Tube* */
    addParams(CE_0162_1, "GTT"); /* Gastrostomy Tube */
    addParams(CE_0162_1, "GU");  /* GU Irrigant */
    addParams(CE_0162_1, "IA");  /* Intra-arterial */
    addParams(CE_0162_1, "IB");  /* Intrabursal */
    addParams(CE_0162_1, "IC");  /* Intracardiac */
    addParams(CE_0162_1, "ICV"); /* Intracervical (uterus) */
    addParams(CE_0162_1, "ID");  /* Intradermal */
    addParams(CE_0162_1, "IH");  /* Inhalation */
    addParams(CE_0162_1, "IHA"); /* Intrahepatic Artery */
    addParams(CE_0162_1, "IM");  /* Intramuscular */
    addParams(CE_0162_1, "IMR"); /* Immerse (Soak) Body Part */
    addParams(CE_0162_1, "IN");  /* Intranasal */
    addParams(CE_0162_1, "IO");  /* Intraocular */
    addParams(CE_0162_1, "IP");  /* Intraperitoneal */
    addParams(CE_0162_1, "IS");  /* Intrasynovial */
    addParams(CE_0162_1, "IT");  /* Intrathecal */
    addParams(CE_0162_1, "IU");  /* Intrauterine */
    addParams(CE_0162_1, "IV");  /* Intravenous */
    addParams(CE_0162_1, "MM");  /* Mucous Membrane */
    addParams(CE_0162_1, "MTH"); /* Mouth/Throat */
    addParams(CE_0162_1, "NG");  /* Nasogastric */
    addParams(CE_0162_1, "NP");  /* Nasal Prongs* */
    addParams(CE_0162_1, "NS");  /* Nasal */
    addParams(CE_0162_1, "NT");  /* Nasotrachial Tube */
    addParams(CE_0162_1, "OP");  /* Ophthalmic */
    addParams(CE_0162_1, "OT");  /* Otic */
    addParams(CE_0162_1, "OTH"); /* Other/Miscellaneous */
    addParams(CE_0162_1, "PF");  /* Perfusion */
    addParams(CE_0162_1, "PO");  /* Oral */
    addParams(CE_0162_1, "PR");  /* Rectal */
    addParams(CE_0162_1, "RM");  /* Rebreather Mask* */
    addParams(CE_0162_1, "SC");  /* Subcutaneous */
    addParams(CE_0162_1, "SD");  /* Soaked Dressing */
    addParams(CE_0162_1, "SL");  /* Sublingual */
    addParams(CE_0162_1, "TD");  /* Transdermal */
    addParams(CE_0162_1, "TL");  /* Translingual */
    addParams(CE_0162_1, "TP");  /* Topical */
    addParams(CE_0162_1, "TRA"); /* Tracheostomy* */
    addParams(CE_0162_1, "UR");  /* Urethral */
    addParams(CE_0162_1, "VG");  /* Vaginal */
    addParams(CE_0162_1, "VM");  /* Ventimask */
    addParams(CE_0162_1, "WND"); /* Wound */
    addObject<ST>(CE_0162_2, "CE_0162.2", HL7::initialized,
		  HL7::repetition_off);
    addObject<IS>(CE_0162_3, "CE_0162.3", HL7::initialized,
		  HL7::repetition_off);
    addObject<ST>(CE_0162_4, "CE_0162.4", HL7::initialized,
		  HL7::repetition_off);
    addObject<ST>(CE_0162_5, "CE_0162.5", HL7::initialized,
		  HL7::repetition_off);
    addObject<IS>(CE_0162_6, "CE_0162.6", HL7::initialized,
		  HL7::repetition_off);
  }

 public:
  /* Getters */
  /****************************************
   * identifier (ST)
   */
  ST *getCE_0162_1(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_1);
  }

  ST *getIdentifier(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_1);
  }

  bool isCE_0162_1(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isIdentifier(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_1) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * text
   */
  ST *getCE_0162_2(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_2);
  }

  ST *getText(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_2);
  }

  bool isCE_0162_2(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isText(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_2) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * name of coding system
   */
  IS *getCE_0162_3(size_t index = 0) {
    return (IS *)this->getObjectSafe(index, CE_0162_3);
  }

  IS *getNameOfCodingSystem(size_t index = 0) {
    return (IS *)this->getObjectSafe(index, CE_0162_3);
  }

  bool isCE_0162_3(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isNameOfCodingSystem(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_3) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * alternate identifier (ST)
   */
  ST *getCE_0162_4(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_4);
  }

  ST *getAlternateIdentifier(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_4);
  }

  bool isCE_0162_4(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isAlternateIdentifier(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_4) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * alternate text
   */
  ST *getCE_0162_5(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_5);
  }

  ST *getAlternateText(size_t index = 0) {
    return (ST *)this->getObjectSafe(index, CE_0162_5);
  }

  bool isCE_0162_5(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isAlternateText(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_5) != NULL;
    } catch (...) {
    }
    return false;
  }

  /****************************************
   * name of alternate coding system
   */
  IS *getCE_0162_6(size_t index = 0) {
    return (IS *)this->getObjectSafe(index, CE_0162_6);
  }

  IS *getNameOfAlternateCodingSystem(size_t index = 0) {
    return (IS *)this->getObjectSafe(index, CE_0162_6);
  }

  bool isCE_0162_6(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_6) != NULL;
    } catch (...) {
    }
    return false;
  }

  bool isNameOfAlternateCodingSystem(size_t index = 0) {
    try {
      return this->getObject(index, CE_0162_6) != NULL;
    } catch (...) {
    }
    return false;
  }

}; /* End CE_0162 */

} /* End HL7_24 */

#endif /*__CE_0162_v24_H__ */
