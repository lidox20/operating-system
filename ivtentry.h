#ifndef _ivtentry_h_
#define _ivtentry_h_

#include "init.h"

class IVTEntry
{
public:
	static IVTEntry* interruptRoutines[256];

	IVTEntry(unsigned char ivtNo, farPointer routine);
	~IVTEntry();

	void signal();
	void callOldRoutine();

private:
	unsigned char no;
	farPointer newRoutine;
	friend class KernelEv;
};

// PREPAREENTRY Macro
#define PREPAREENTRY(_numEntry, _callOld); \
		void interrupt inter##_numEntry( ... ) { \
			if ( IVTEntry::interruptRoutines[(unsigned char)_numEntry] ) { \
					(IVTEntry::interruptRoutines[(unsigned char)_numEntry])->signal(); \
					if(_callOld == 1) (IVTEntry::interruptRoutines[ (unsigned char) _numEntry ])->callOldRoutine(); \
			}; \
		}; \
		IVTEntry newIVTEntry##num((unsigned char)_numEntry, inter##_numEntry);

#endif
