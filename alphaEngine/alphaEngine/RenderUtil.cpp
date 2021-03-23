#include "RenderUtil.h"

namespace RenderUtil
{
	void RenderWithSolidColour(AEGfxVertexList* mesh, GameObject& obj)
	{
		AEGfxSetRenderMode(AE_GFX_RM_COLOR);
		AEGfxSetTransform(obj.transform.GetTransformationMatrix()->m);
		AEGfxSetTintColor(obj.colour.GetR(), obj.colour.GetG(), obj.colour.GetB(), obj.colour.GetA());
		AEGfxSetTransparency(obj.colour.GetA());
		// Set texture
		//AEGfxTextureSet(nullptr, 0.0f, 0.0f);
		// Drawing the mesh (list of triangles)
		AEGfxMeshDraw(mesh, AE_GFX_MDM_TRIANGLES);
	}
}