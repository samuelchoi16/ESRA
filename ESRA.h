/*
 * ESRA - Equipment Status Reporting Agent
 *
 * Author: Samuel Choi, PhD (samuelchoi@irm.kr)
 * Date: 2017-07-04
 */

#ifndef ESRA_H
#define ESRA_H

#include <string>
#include <list>
#include "2.4/message/ORU_R01.h"
#include "2.4/message/ACK.h"

namespace esra {

typedef	std::string	String;

class ESRA
{
protected:
	static String __sendingApplication[3];
	static String __sendingFacility[3];
	static String __receivingApplication[3];
	static String __receivingFacility[3];

	HL7_24::ORU_R01 _hl7_ORU_R01;
	HL7_24::ACK _hl7_ACK;

	String _messageControlId;

public:
	static void setSendingApplication(String name, String id = "", String idType = "");
	static void setSendingFacility(String name, String id = "", String idType = "");
	static void setReceivingApplication(String name, String id = "", String idType = "");
	static void setReceivingFacility(String name, String id = "", String idType = "");

	ESRA();
	virtual ~ESRA();

	void clear();

	String getTimestamp();

	HL7_24::MSH* getMSH();
	HL7_24::MSH* getMessageHeader();

	HL7_24::PID* getPID();
	HL7_24::PID* getPatientID();

	HL7_24::OBR* getOBR();
	HL7_24::OBR* getOrderInfo();
	void setOrderInfo(String idValue, String issuerName, String issuerId, String issuerIdType, String code, String meaning, String system);

	HL7_24::OBX* addOBX();
	HL7_24::OBX* addDeviceInfo();

	HL7_24::OBX* getOBX(int index);
	HL7_24::OBX* getDeviceInfo(int index);

	HL7_24::MSA *getMSA();
	HL7_24::MSA* getResponse();

	String getRequestMessageAsText();
	String getResponseMessageAsText();

	bool send(String hostname, int port);
};

}

#endif // ESRA_H
