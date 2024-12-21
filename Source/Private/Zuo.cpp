// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#define LOCTEXT_NAMESPACE "ZuoModule"
#include "zuo.hpp"

class FZuoModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override{

		/* Step 1 */
		zuo_ext_primitive_init();

		/* Step 2 */
		zuo_ext_image_init(NULL);

		/* Step 3 */
		zuo_ext_runtime_init(zuo_ext_false(), zuo_ext_empty_hash());
    }
	virtual void ShutdownModule() override{

    }
};


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FZuoModule, Zuo)