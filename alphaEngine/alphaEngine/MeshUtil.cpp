#include "MeshUtil.h"
#include "AEEngine.h"

namespace MeshUtil
{
	AEGfxVertexList* CreateRect(float width, float height, float texU, float texV)
	{
		AEGfxVertexList* temp = nullptr;
		// Informing the library that we're about to start adding triangles
		AEGfxMeshStart();

		// This shape has 2 triangles
		AEGfxTriAdd(
			-width / 2, -height / 2, 0xFFFFFFFF, 0.0f, texV,
			width / 2, -height / 2, 0xFFFFFFFF, texU, texV,
			-width / 2, height / 2, 0xFFFFFFFF, 0.0f, 0.0f);

		AEGfxTriAdd(
			width / 2, -height / 2, 0xFFFFFFFF, texU, texV,
			width / 2, height / 2, 0xFFFFFFFF, texU, 0.0f,
			-width / 2, height / 2, 0xFFFFFFFF, 0.0f, 0.0f);
		temp = AEGfxMeshEnd();

		return temp;
	}

}


