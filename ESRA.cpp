#include "common/hl7mllp.h" // place hl7mllp.h file as first include in the source file
#include <stdio.h>
#include <time.h>

#ifdef WIN32
#include <Windows.h>
#endif

#include <string>
#include <sys/timeb.h>
#include "common/dataencode.h"
#include "common/ObjToPipe.h"

#include "ESRA.h"

#ifdef WIN32
// encode string time stamp in TS format from SYSTEMTIME and timezone
std::string encodeTimeStamp(SYSTEMTIME& st, short zone)
#else // WIN32
// encode string time stamp in TS format from struct tm and timezone
std::string encodeTimeStamp(timeb& st)
#endif // WIN32
{
	std::string encoded_val;
	try {
#ifdef WIN32
		// use dataencode functtion for TS data encoding
		if (!encodeTS(encoded_val, st.wYear, st.wMonth, st.wDay,
			st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, zone)) {
#else // WIN32
		struct tm* tmTime = localtime (&st.time);
		// use dataencode functtion for TS data encoding
		if (!encodeTS(encoded_val, tmTime->tm_year, tmTime->tm_mon, tmTime->tm_mday,
			tmTime->tm_hour, tmTime->tm_min, tmTime->tm_sec, st.millitm, st.timezone)) {
#endif // WIN32
			encoded_val = "000000000000";
		}
	} catch (...) {
		printf("ERROR constructing TS data.\n");
		encoded_val = "000000000000";
	}
	return encoded_val;
}

using namespace esra;

String ESRA::__sendingApplication[3];
String ESRA::__sendingFacility[3];
String ESRA::__receivingApplication[3];
String ESRA::__receivingFacility[3];

void ESRA::setSendingApplication(String name, String id, String idType)
{
	__sendingApplication[0] = name;
	__sendingApplication[1] = id;
	__sendingApplication[2] = idType;
}

void ESRA::setSendingFacility(String name, String id, String idType)
{
	__sendingFacility[0] = name;
	__sendingFacility[1] = id;
	__sendingFacility[2] = idType;
}

void ESRA::setReceivingApplication(String name, String id, String idType)
{
	__receivingApplication[0] = name;
	__receivingApplication[1] = id;
	__receivingApplication[2] = idType;
}

void ESRA::setReceivingFacility(String name, String id, String idType)
{
	__receivingFacility[0] = name;
	__receivingFacility[1] = id;
	__receivingFacility[2] = idType;
}

ESRA::ESRA()
{
	clear();
}

ESRA::~ESRA()
{

}

String ESRA::getTimestamp()
{
#ifdef WIN32
	__timeb64 tm;
	SYSTEMTIME time;
	_ftime64(&tm);
	GetSystemTime(&time);
	std::string curTime = encodeTimeStamp(time, tm.timezone);
#else
	timeb tm;
	ftime(&tm);
	std::string curTime = encodeTimeStamp(tm);
#endif
	return curTime;
}

void ESRA::clear()
{
	_hl7_ORU_R01.clear();
	_hl7_ACK.clear();

	static int __seq = 0;
	std::ostringstream id_oss;
	id_oss << time(NULL) << ++__seq;
	_messageControlId = id_oss.str();

	String curTime = getTimestamp();

	/*
	 * Example MEMDMC.hl7
	 *
	MSH|^~\&|Smiths Medical^001A010000000001^EUI-64||Smiths Customer||20150119221713-0000||ORU^R01^ORU_R01|1421727433|P|2.6|||AL|NE||UNICODE UTF-8|en^English^ISO639||IHE_PCD_015^IHE PCD^1.3.6.1.4.1.19376.1.6.1.15.1^ISO
	PID|1||||||||||||||||||||||||||||||Y PV1|1|N
	OBR|1|2000101^Medfusion 4000^001A010000000001^EUI-64|2000101^Medfusion 4000^001A010000000001^EUI-64|0^MDCX_EVT_POWER_CHG^MDC||20150119221713- 0000
	OBX|1|ST|69985^MDC_DEV_PUMP_INFUS_MDS^MDC|1.0.0.0|||||||X
	OBX|2|ST|67880^MDC_ATTR_ID_MODEL^MDC|1.0.0.1|manufacturer=Smiths Medical model=Medfusion 4000||20150119221713-0000||||R
	OBX|3|ST|67972^MDC_ATTR_SYS_ID^MDC|1.0.0.2|2000101^Medfusion 4000^001A010000000001^EUI-64||20150119221713-0000||||R
	OBX|4|CWE|0^MDCX_DMC_ATTR_POWER_STATE^MDC|1.0.0.3|^OFF||20150119221713-0000||||F|||||||2000101^Medfusion 4000^001A010000000001^EUI-64
	OBX|5|ST|0^MDCX_LS_ATTR_NAME^MDC|LOC|IV Pump 2012078||||||F|||20150127110822.229-0800
	OBX|6|PL|0^MDCX_LS_ATTR_LOCATION^MDC|LOC|^^^Fraser Health^^^North Building^Main Floor^Nurse Station||||||F|||20150127110822.229- 0800||||112213000174^GuardRFID^^L
	OBX|7|NM|0^MDCX_LS_ATTR_COORD_X^MDC|LOC|406|263441^MDC_DIM_CENTI_M^MDC|||||F|||20150127110822.229-0800||||112213000174^GuardRFID^^L
	OBX|8|NM|0^MDCX_LS_ATTR_COORD_Y^MDC|LOC|917|263441^MDC_DIM_CENTI_M^MDC|||||F|||20150127110822.229-0800||||112213000174^GuardRFID^^L
	OBX|9|NM|0^MDCX_LS_ATTR_COORD_Z^MDC|LOC|0|263441^MDC_DIM_CENTI_M^MDC|||||F|||20150127110822.229-0800||||112213000174^GuardRFID^^L
	 */
	try
	{
		// init MSH segment
	//	MSH|^~\&|Smiths Medical^001A010000000001^EUI-64||Smiths Customer||20150119221713-0000||ORU^R01^ORU_R01|1421727433|P|2.6|||AL|NE||UNICODE UTF-8|en^English^ISO639||IHE_PCD_015^IHE PCD^1.3.6.1.4.1.19376.1.6.1.15.1^ISO
		HL7_24::MSH* msh = _hl7_ORU_R01.getMSH_1();
		msh->getEncodingCharacters()->setData("^~\\&");
		msh->getSendingApplication()->getNamespaceID()->setData(__sendingApplication[0]);
		msh->getSendingApplication()->getUniversalID()->setData(__sendingApplication[1]);
		msh->getSendingApplication()->getUniversalIDType()->setData(__sendingApplication[2]);
		msh->getSendingFacility()->getNamespaceID()->setData(__sendingFacility[0]);
		msh->getSendingFacility()->getUniversalID()->setData(__sendingFacility[1]);
		msh->getSendingFacility()->getUniversalIDType()->setData(__sendingFacility[2]);
		msh->getReceivingApplication()->getNamespaceID()->setData(__receivingApplication[0]);
		msh->getReceivingApplication()->getUniversalID()->setData(__receivingApplication[1]);
		msh->getReceivingApplication()->getUniversalIDType()->setData(__receivingApplication[2]);
		msh->getReceivingFacility()->getNamespaceID()->setData(__receivingFacility[0]);
		msh->getReceivingFacility()->getUniversalID()->setData(__receivingFacility[1]);
		msh->getReceivingFacility()->getUniversalIDType()->setData(__receivingFacility[2]);
		msh->getDateTimeOfMessage()->getTimeOfAnEvent()->setData(curTime);
		msh->getMessageType()->getMessageType()->setData("ORU");
		msh->getMessageType()->getTriggerEvent()->setData("R01");
		msh->getMessageType()->getMessageStructure()->setData("ORU_R01");
		msh->getMessageControlID()->setData(_messageControlId);
		msh->getProcessingID()->getProcessingID()->setData("P");
		msh->getVersionID()->getVID_1()->setData("2.6");
		msh->getAcceptAcknowledgmentType()->setData("AL");
		msh->getApplicationAcknowledgmentType()->setData("NE");
		msh->getCharacterSet()->setData("UNICODE UTF-8");
		msh->getPrincipalLanguageOfMessage()->getIdentifier()->setData("en");
		msh->getPrincipalLanguageOfMessage()->getText()->setData("English");
		msh->getPrincipalLanguageOfMessage()->getNameOfCodingSystem()->setData("ISO639");
		msh->getConformanceStatementID()->setData("IHE_PCD_015^IHE PCD^1.3.6.1.4.1.19376.1.6.1.15.1^ISO");

		// init PID segment
	//	PID|1||||||||||||||||||||||||||||||Y PV1|1|N
		HL7_24::PID* pid = _hl7_ORU_R01.getPATIENT_RESULT()->getPATIENT()->getPID_4();
		pid->getSetIDPID()->setData("1");
		pid->getIdentityUnknownIndicator()->setData("Y PV1");
		pid->getIdentityReliabilityCode()->setData("1");
		pid->getLastUpdateDateTime()->getTimeOfAnEvent()->setData("N");
	} catch (...) {
		printf("ERROR constructing ORU_R01 message.\n");
	}
}

HL7_24::MSH* ESRA::getMSH()
{
	HL7_24::MSH* msh = _hl7_ORU_R01.getMSH_1();
	return msh;
}

HL7_24::MSH* ESRA::getMessageHeader()
{
	return getMSH();
}

HL7_24::PID* ESRA::getPID()
{
	HL7_24::PID* pid = _hl7_ORU_R01.getPATIENT_RESULT()->getPATIENT()->getPID_4();
	return pid;
}

HL7_24::PID* ESRA::getPatientID()
{
	return getPID();
}

HL7_24::OBR* ESRA::getOBR()
{
	HL7_24::OBR* obr = _hl7_ORU_R01.getPATIENT_RESULT()->getORDER_OBSERVATION()->getOBR_29();
	return obr;
}

HL7_24::OBR* ESRA::getOrderInfo()
{
	return getOBR();
}

void ESRA::setOrderInfo(String idValue, String issuerName, String issuerId, String issuerIdType, String code, String meaning, String system)
{
	String curTime = getTimestamp();

	// init OBR segment
	// OBR|1|2000101^Medfusion 4000^001A010000000001^EUI-64|2000101^Medfusion 4000^001A010000000001^EUI-64|0^MDCX_EVT_POWER_CHG^MDC||20150119221713-0000
	HL7_24::OBR* obr = getOBR();
	obr->getSetIDOBR()->setData("1");
	obr->getPlacerOrderNumber()->getEntityIdentifier()->setData(idValue);
	obr->getPlacerOrderNumber()->getNamespaceID()->setData(issuerName);
	obr->getPlacerOrderNumber()->getUniversalID()->setData(issuerId);
	obr->getPlacerOrderNumber()->getUniversalIDType()->setData(issuerIdType);
	obr->getFillerOrderNumber()->getEntityIdentifier()->setData(idValue);
	obr->getFillerOrderNumber()->getNamespaceID()->setData(issuerName);
	obr->getFillerOrderNumber()->getUniversalID()->setData(issuerId);
	obr->getFillerOrderNumber()->getUniversalIDType()->setData(issuerIdType);
	obr->getUniversalServiceIdentifier()->getIdentifier()->setData(code);
	obr->getUniversalServiceIdentifier()->getText()->setData(meaning);
	obr->getUniversalServiceIdentifier()->getNameOfCodingSystem()->setData(system);
	obr->getRequestedDateTime()->getTimeOfAnEvent()->setData(curTime);
}

HL7_24::OBX* ESRA::addOBX()
{
	int index = _hl7_ORU_R01.getPATIENT_RESULT()->getORDER_OBSERVATION()->getOBSERVATION()->size();
	HL7_24::OBX* obx = _hl7_ORU_R01.getPATIENT_RESULT()->getORDER_OBSERVATION()->getOBSERVATION()->getOBX_40(index);
	return obx;
}

HL7_24::OBX* ESRA::getOBX(int index)
{
	int count = _hl7_ORU_R01.getPATIENT_RESULT()->getORDER_OBSERVATION()->getOBSERVATION()->size();
	if (index >= 0 && index < count) {
		HL7_24::OBX* obx = _hl7_ORU_R01.getPATIENT_RESULT()->getORDER_OBSERVATION()->getOBSERVATION()->getOBX_40(index);
		return obx;
	} else {
		return NULL;
	}
}

HL7_24::OBX* ESRA::addDeviceInfo()
{
	return addOBX();
}

HL7_24::OBX* ESRA::getDeviceInfo(int index)
{
	return getOBX(index);
}

HL7_24::MSA* ESRA::getMSA()
{
	return _hl7_ACK.getMSA_2();
}

HL7_24::MSA* ESRA::getResponse()
{
	return getMSA();
}

String ESRA::getRequestMessageAsText()
{
	String requestMessageAsText;
	msgToPipe(&_hl7_ORU_R01, requestMessageAsText);
	return requestMessageAsText;
}

String ESRA::getResponseMessageAsText()
{
	String responseMessageAsText;
	msgToPipe(&_hl7_ACK, responseMessageAsText);
	return responseMessageAsText;
}

bool ESRA::send(String hostname, int port)
{
	String requestMessageAsText = getRequestMessageAsText();
	String responseMessageAsText;

	// create MLLP client socket
	std::ostringstream port_oss;
	port_oss << port;
	HL7MLLP sock(hostname.c_str(), port_oss.str());
	try {
		// send request
		printf("sending message:\n%s\n", requestMessageAsText.c_str());
		sock.send_msg_mllp(requestMessageAsText);

		// receive answer
		sock.read_msg_mllp(responseMessageAsText);
		printf("received message:\n%s\n", responseMessageAsText.c_str());
	} catch (...) {
		printf("ERROR sending ORU_R01 message or receiving result.\n");
		return false;
	}

	try {
		std::string data;
		// convert answer to message
		pipeToMsg(&_hl7_ACK, responseMessageAsText);
		// get answer acknowledgement code
		_hl7_ACK.getMSA_2()->getAcknowledgementCode()->getData(requestMessageAsText);
		if ((requestMessageAsText != "AA") && (requestMessageAsText != "CA")) {
			// check if there error
			// check if there is extended error
			if (_hl7_ACK.isERR_4()) {
				// print extended error data
				_hl7_ACK.getERR_4()->getErrorCodeAndLocation()->getSegmentID()->getData(data);
				printf("ERROR Acknowledgment code = <%s>, segment = <%s>, sequence = <", requestMessageAsText.c_str(), data.c_str());
				_hl7_ACK.getERR_4()->getErrorCodeAndLocation()->getSequence()->getData(data);
				printf("%s>, field = <", data.c_str());
				_hl7_ACK.getERR_4()->getErrorCodeAndLocation()->getFieldPosition()->getData(data);
				printf("%s>; = ", data.c_str());
				_hl7_ACK.getERR_4()->getErrorCodeAndLocation()->getCodeIdentifyingError()->getIdentifier()->getData(data);
				printf("%s .\n", data.c_str());
			} else {
				// print short error data
				_hl7_ACK.getMSA_2()->getErrorCondition()->getIdentifier()->getData(data);
				printf("ERROR Acknowledgment code = <%s>, Error Condition = <", requestMessageAsText.c_str(), data.c_str());
				_hl7_ACK.getMSA_2()->getTextMessage()->getData(data);
				printf("%s>.\n", data.c_str());
			}
			return false;
		}

		// check if it is answer for our request
		std::string messageControlIdReceived;
		_hl7_ACK.getMSA_2()->getMessageControlID()->getData(messageControlIdReceived);
		if (messageControlIdReceived != _messageControlId){
			// it is not our answer
			printf("ERROR answer MessageControlID <%s> does not equal to request MessageControlID <%s>.\n",
					messageControlIdReceived.c_str(), _messageControlId.c_str());
			return false;
		}
	 } catch (...) {
		printf("ERROR sending ORU_R01 message or receiving result.\n");
		return false;
	 }

	return true;
}
