#include "CPP_FlyingBrick.h"


ACPP_FlyingBrick::ACPP_FlyingBrick()
{
	PrimaryActorTick.bCanEverTick = true;

	//Create find FBX asset in /Content/Assets/
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/Assets/Brick.Brick'"));
	UStaticMesh* Asset = MeshAsset.Object;

	//Create StaticMesh Component and set it as a root component of this Actor
	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent"); //
	staticMeshComponent->SetStaticMesh(Asset);
	staticMeshComponent->SetSimulatePhysics(true);
	staticMeshComponent->SetMassOverrideInKg(NAME_None, 100.0f, true);
	
	//constraint this actor from moving by X and Y, and from rotating
	staticMeshComponent->GetBodyInstance()->bLockRotation = true;
	staticMeshComponent->GetBodyInstance()->bLockXTranslation = true;
	staticMeshComponent->GetBodyInstance()->bLockYTranslation = true;
	RootComponent = staticMeshComponent;


	//Create PID ActorComponent from UPIDComponent
	PIDComponent = CreateDefaultSubobject<UPIDComponent>("PIDController");
	
	//Create and setup TextRenderer Component
	TextComponent = CreateDefaultSubobject<UTextRenderComponent>("TextComponent");
	TextComponent->SetupAttachment(RootComponent);
	TextComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	TextComponent->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TextComponent->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	TextComponent->SetTextRenderColor(FColor::Red);
}

void ACPP_FlyingBrick::BeginPlay()
{
	Super::BeginPlay();

	staticMeshComponent->CreateDynamicMaterialInstance(0, brickMaterial);
	
}

void ACPP_FlyingBrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	float currentAltitude = GetActorLocation().Z; //current world location Z

	//Request PID to calculate Force, AddForce to actor z-axis
	float Fz = PIDComponent->Calculate(SetAltitude, currentAltitude, PID_P, PID_I, PID_D, DeltaTime); 
	staticMeshComponent->AddForce(FVector(0.0f, 0.0f, Fz), NAME_None, false);

	//Set TextRenderer's content
	FString txt = FString::Printf(TEXT("Set Altitude = %f\nCurrent Altitude = %f\nPID_P: %f\nPID_I: %f\nPID_D: %f"), SetAltitude, currentAltitude, PID_P, PID_I, PID_D);
	TextComponent->SetText(txt);

}

