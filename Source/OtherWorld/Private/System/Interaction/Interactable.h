#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h" 

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface {
	GENERATED_BODY()
};

class OTHERWORLD_API IInteractable {
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void Interact(const AActor* Caller);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	class TObjectPtr<UAnimMontage> Anim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	class TObjectPtr<USoundBase> Sound;
	UFUNCTION(BlueprintImplementableEvent, Category = "Visual")
	void OnVisual();
};
