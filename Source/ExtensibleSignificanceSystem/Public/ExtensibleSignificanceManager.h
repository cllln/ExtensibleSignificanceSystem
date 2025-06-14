// Copyright Chengll, Inc. All Rights Reserved.

#pragma once

#include "SignificanceManager.h"

#include "ExtensibleSignificanceManager.generated.h"

UCLASS()
class EXTENSIBLESIGNIFICANCESYSTEM_API UExtensibleSignificanceManager : public USignificanceManager
{
	GENERATED_BODY()
	
public:
	UExtensibleSignificanceManager();

	struct FExtendedManagedObject;
	typedef TFunction<void(FExtendedManagedObject*, int32, int32)> FManagedObjectPostLodFunction;
	
	struct FExtendedManagedObject final : FManagedObjectInfo
	{
		FExtendedManagedObject()
			: FManagedObjectInfo()
		{}
		
		FExtendedManagedObject(UObject* InObject, FName InTag, FManagedObjectSignificanceFunction InSignificanceFunction, EPostSignificanceType InPostSignificanceType = EPostSignificanceType::None, FManagedObjectPostSignificanceFunction InPostSignificanceFunction = nullptr, FManagedObjectPostLodFunction InPostLodFunction = nullptr)
			: FManagedObjectInfo(InObject, InTag, InSignificanceFunction, InPostSignificanceType, InPostSignificanceFunction)
			, PostLodFunction(MoveTemp(InPostLodFunction))
		{
		}

		int32 LOD = -1;
		// The LOD that should have been located, because the original LOD may be full, and it will be replaced with a new LOD.
		int32 ShouldBeLOD = -1;
		FManagedObjectPostLodFunction PostLodFunction = nullptr;
	};
	
	virtual void Update(TArrayView<const FTransform> InViewpoints) override;

	// Custom Register
	virtual void CustomRegisterObject(UObject* Object, FName Tag, FManagedObjectSignificanceFunction SignificanceFunction, FManagedObjectPostLodFunction InPostLodFunction, EPostSignificanceType InPostSignificanceType = EPostSignificanceType::None, FManagedObjectPostSignificanceFunction InPostSignificanceFunction = nullptr);
	
	// Get Extensible Significance Manager
	UFUNCTION(BlueprintCallable, Category = SignificanceSystem)
	static UExtensibleSignificanceManager* GetExtensibleSignificanceManager(UObject* WorldContext);

	// Returns the Lod value for a given object, returns 0 if object is not managed
	UFUNCTION(BlueprintCallable, Category = SignificanceSystem)
	float GetLod(UObject* Object) const;

	// Returns true if the object is being tracked, placing the lod value in OutLod (or 0 if object is not managed)
	bool QueryLod(UObject* Object, int32& OutLod) const;

	// UnRegister All
	void UnRegisterAllSignificance();
	
private:
	TSet<FName> RegisteredTags;
};
