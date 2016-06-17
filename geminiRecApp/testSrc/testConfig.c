#include <stdio.h>

#include <epicsTypes.h>
#include <genSubRecord.h>
#include <cad.h>
#include <cadRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

#include "testInterlock.h"

/*+
 *   Function name:
 *   testConfigBegin
 *
 *   Purpose:
 *   Begin a new test configuration.
 *
 *   Description:
 *   This routine is called as soon as a new configuration is started by
 *   the OCS or by an engineering screen. It is tied to a cad record
 *   which is in turn the first record triggered by the top level Apply
 *   record. It will get called the top level Apply both when preset and
 *   start are issued. Any code that needs to be executed before preset
 *   or start is issued to any commands should be executed from this
 *   routine.
 *
 *   Invocation:
 *   testConfigBegin (pcad) 
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pcad     (cadRecord *)  Pointer to cad structure
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *   External functions:
 *   Any external functions used in this function or procedure e.g
 *   function1      (library name)     What function does
 *
 *   External variables:
 *   Any external variables used in this function or procedure e.g.
 *   (>)   <name>    <C type>    <variable description>
 *
 *   Deficiencies:
 *   Any known problems with the function
 *
 *-
 */

long testConfigBegin( cadRecord *pcad )
{

    long status;                      /* return status */
    double tnow ;                     /* Raw time now */


/* Check for interlocks */

    if (testInterlocked(pcad->mess))
        status = CAD_REJECT;
    else {
        status = CAD_ACCEPT;
        switch (pcad->dir) {
        case menuDirectivePRESET:

/* Since this is the first user routine that will be called by the test
*  when a command is issued. Provide a time stamp if the debug level is
*  set to the correct value. These diagnostics are used in ST02000 and 
*  ST02003. 
*/
            //(void) timeNow(&tnow) ;
            //DBGMSGREAL (DBG_FULL, "testConfigBegin: preset at ", tnow) ;
            //testConfigBeginPreset();
            printf("testConfigBegin: preset at <ADD TIMESTAMP>...\n");
            break;

        case menuDirectiveSTART:
            //(void) timeNow(&tnow) ;
            //DBGMSGREAL (DBG_FULL, "testConfigBegin: start at ", tnow) ;
            //testConfigBeginStart();
            printf("testConfigBegin: start at <ADD TIMESTAMP>...\n");
            break;

        default:
            break;
        }
    }

    return status;
}

long testConfigEnd( cadRecord *pcad )
{

    long status;                      /* return status */
    status = CAD_ACCEPT;
    switch (pcad->dir) {
        case menuDirectivePRESET:
            printf("testConfigEnd: preset at <ADD TIMESTAMP>...\n");
            break;
        case menuDirectiveSTART:
            printf("testConfigEnd: start at <ADD TIMESTAMP>...\n");
            break;
        default:
            break;
    }
    return status;
}

/*+
 *   Function name:
 *   testConfigSeqCheck
 *
 *   Purpose:
 *   Check sequence commands for consistency.
 *
 *   Description:
 *   Once all the sequence commands have been preset, this routine is invoked
 *   to make sure that those commands that have been issued are consistent.
 *   At present this is done prior to checking the test configuration and the
 *   criterion used is that there must only be one sequence command in
 *   a configuration. In principle some sequence commands could be issued
 *   in parallel but at present this is not required. The commands that
 *   potentially could be issued in parallel are
 *
 *   1. observe, pause, continue, stop, abort or endobserve with guide or
 *      endguide
 *   2. stop, abort or endobserve with park
 *
 *   Invocation:
 *   testConfigSeqCheck(pcad)
 *
 *   Parameters: (">" input, "!" modified, "<" output)  
 *      (!)    pcad    (struct cadRecord *)  Pointer to cad structure
 *
 *   Function value:
 *   (<)  status  (long)  Return status, 0 = OK
 * 
 *   External functions:
 *   Any external functions used in this function or procedure e.g
 *   function1      (library name)     What function does
 *
 *   External variables:
 *   Any external variables used in this function or procedure e.g.
 *   (>)   <name>    <C type>    <variable description>
 *
 *   Prior requirements:
 *   Operations that must be performed before calling this function
 *
 *   Deficiencies:
 *   Any known problems with the function
 *
 *-
 */

long testConfigSeqCheck( cadRecord *pcad )
{
    long status;                /* return status */

    status = CAD_ACCEPT;

    switch (pcad->dir) {
    case menuDirectivePRESET:
        break;

    default:
        break;

    }

    return status;


}

epicsRegisterFunction( testConfigBegin     );
epicsRegisterFunction( testConfigEnd       );
epicsRegisterFunction( testConfigSeqCheck  );
