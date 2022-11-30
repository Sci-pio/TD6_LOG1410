#include "AbsDirectoryComponent.h"

std::ostream& operator<<(std::ostream & o, const AbsDirectoryComponent & dc)
{
	return dc.printToStream(o);
}