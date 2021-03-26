


Blue Noise Dither PostProcess Material for Unreal Engine

acat@acatalept.com

Made with UE 4.25, but should work with recent previous versions as well.

Uses general PostProcess material concepts explained in more detail here if you're unfamiliar:

   https://docs.unrealengine.com/en-US/Engine/Rendering/PostProcessEffects/PostProcessMaterials/index.html



Instructions:

1. Extract the Materials and Textures folders into your project's Content folder

2. In your level, use a new or existing PostProcess Volume with "Infinite Extend (Unbound)" enabled

3. In the PostProcess Volume, under Rendering Features -> PostProcess Materials, add a new array element, and use the dropdown to select one of the these:

   MI_PP_DitherFlipbook: material instance to allow adjusting effect strength at runtime
	 
	 M_PP_DitherFlipbook: base material with strength defaulting to 0.05
	 

	 