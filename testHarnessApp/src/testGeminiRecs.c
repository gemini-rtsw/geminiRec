#include <string.h>
#include <cad.h>

#include <epicsStdioRedirect.h>
#include <epicsStdlib.h>
#include <epicsTypes.h>
#include <epicsMath.h>
#include <epicsString.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <genSubRecord.h>
#include <cadRecord.h>
#include <menuCarstates.h>
#include <epicsExport.h>
#include <registryFunction.h>
#include <tcslib.h>

#define ERROR (-1)
#define OK      0


/*+
 *   Function name:
 *   tcsSimpleSeqComm
 *
 *   Purpose:
 *   Implement a simple OCS sequence command
 *
 *   Description:
 *   At present this routine has nothing to do as there are no parameters
 *   associated with the command. Hence there is nothing to check and
 *   everything is handled by EPICS.
 *
 *   At present the output message does not appear in the mess field
 *   due to the current implementation of the CAD
 *
 *   Invocation:
 *   tcsSimpleSeqComm (pcad) 
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pcad     (struct cadRecord *) CAD record structure
 *
 *   Function value:
 *   (<) status (long) Status return, 0 = OK
 * 
 *-
 */
#include <tcsSubsysCadSupport.h>
extern char* tcsCsCadName( struct cadRecord* pcad);

long tcsSimpleSeqComm ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  char *comname;         /* Command name without prefix */

  status = CAD_ACCEPT ;
  comname = tcsCsCadName( pcad );

  switch (pcad->dir)
  {
    case menuDirectiveMARK:
#if 0
    printf ("%s: mark received\n", pcad->name) ;
#endif
    tcsCsSetMessageN( pcad, comname, ": MARK accepted", (char*)NULL);
    break ;

    case menuDirectivePRESET :
#if 1
    printf ("%s: preset received\n", pcad->name) ;
#endif
    //status = tcsConfigMarkSeqComm(pcad->name, pcad->mess)  ;
    //if (status)
    //  status = CAD_REJECT ;
    //break ;

    case menuDirectiveSTART :
#if 1
    printf ("%s:  start received\n", pcad->name) ;
#endif
    tcsCsSetMessageN( pcad, comname, ": START accepted", (char*)NULL);
    break ;

    case menuDirectiveSTOP :
#if 1
    printf ("%s: stop received\n", pcad->name) ;
#endif
    tcsCsSetMessageN( pcad, pcad->name, ": ", comname, 
       " cannot be stopped", (char*)NULL);
    break ;

    case menuDirectiveCLEAR :
#if 1
    printf ("%s: clear received\n", pcad->name) ;
#endif
    tcsCsSetMessageN( pcad, comname, ": CLEAR accepted", (char*)NULL);
    break ;

    default :
#if 1
    printf ("%s: default\n", pcad->name) ;
#endif
    tcsCsSetMessageN( pcad, comname, ": Unrecognised directive", (char*)NULL);
    status = CAD_REJECT ;
    break ;

  }
  return status ;
}



long testCADinit ( struct cadRecord *pcad)

{
   long status ;          /* return status */
   status = tcsSimpleSeqComm(pcad);
   return status ;

}
epicsRegisterFunction(testCADinit);

long testCADreboot ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADreboot);

long testCADdatum ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);

/* This is something of a fudge. The datum command is specified to have 
*  no parameters. Unfortuneately, the mount has a number of different
*  ways to datum which require additional parameters to be sent to it. 
*  The TCS gets round this by sending default values which have been
*  initialised by pvload. 
*  N.B. field A can't be used as the OCS writes "MARK" into this field
*/  
  if (pcad->dir == menuDirectiveSTART) {
    strncpy (pcad->valb, pcad->b, MAX_STRING_SIZE) ;
    strncpy (pcad->valc, pcad->c, MAX_STRING_SIZE) ;
    strncpy (pcad->vald, pcad->d, MAX_STRING_SIZE) ;
  } ;
    
  return status ;

}
epicsRegisterFunction(testCADdatum);

long testCADtest ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADtest);

long testCADobserve ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADobserve);

long testCADendObserve ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADendObserve);

long testCADpause ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADpause);

long testCADcontinue ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADcontinue);

long testCADabort ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADabort);

long testCADstop ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADstop);

long testCADguide ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADguide);

long testCADendGuide ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADendGuide);

long testCADverify ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADverify);

long testCADendVerify ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  return status ;

}
epicsRegisterFunction(testCADendVerify);

long testCADpark ( struct cadRecord *pcad)

{
  long status ;          /* return status */
  status = tcsSimpleSeqComm(pcad);
  if (pcad->dir == menuDirectiveSTART) {

/* Set parameter for PARKing M1 */
    strncpy(pcad->vala, "PARK", 4) ;

/* Make sure that automatic updates of the dome & shutters are disabled */
    //testEcsEnableDome (FALSE);
    //testEcsEnableShtrs (FALSE);
  }
  return status ;

}
epicsRegisterFunction(testCADpark);
