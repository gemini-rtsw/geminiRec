
#include <registryFunction.h>
#include <epicsExport.h>
#include <subRecord.h>
#include <string.h>

#include "testInterlock.h"

static int Interlocked ; /* True ( = 1) if GIS has requested an interlock */

/*+
 *   Function name:
 *   testInterLock
 *
 *   Purpose:
 *   Saves interlock state set by the GIS
 *
 *   Description:
 *   The Gemini Interlock System can send an interlock demand to the test.
 *   This routine saves the state of that demand for use by other parts
 *   of the test.
 *
 *   Invocation:
 *   testInterlock (psub)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    psub     (struct subRecord *) Pointer to subroutine structure
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *-
 */

long testInterlock (struct subRecord *psub) 

{

 long status ;

 Interlocked = psub->a ;

 status = 0 ;

 return status ;
  
}

/*+
 *   Function name:
 *   testInterlocked 
 *
 *   Purpose:
 *   Queries the interlock state of the test
 *
 *   Description:
 *   The test is required to interlock out all commands whenever the GIS
 *   has issued an interlock demand. It is also necessary to interlock out
 *   commands at system boot time to prevent users issuing commands
 *   before the test has properly initialised. This routine returns a
 *   flag that enables a calling routine to determine if either of these
 *   interlock conditions are true. It is intended that this routine
 *   is called by every CAD routine before any other processing. If an
 *   interlock is present a descriptive message is also returned which the
 *   CAD can return in its MESS field.
 *
 *   Invocation:
 *   interlock = testInterlocked(message)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (<)    mess     (char * )  message string
 *
 *   Function value:
 *   (<)  interlock  (int)  0 = no interlock, 1 = interlock in place 
 * 
 *-
 */

int testInterlocked (char *message)

{

  if (Interlocked)
  {
    strcpy (message, "GIS Interlock present") ;
    return (Interlocked) ;
  }

  //TODO: Add testState 
  //if (testState != RUNNING)
  //{
  //  strcpy (message, "test still initialising");
  //  return (1) ;
  //}

  //if (pvloadFailed) {
  //  strcpy (message, "pvload failed - fix file then reboot");
  //  return (pvloadFailed) ;
  //}

  strcpy (message, " ") ;
  return 0 ;

}

epicsRegisterFunction(testInterlock);

