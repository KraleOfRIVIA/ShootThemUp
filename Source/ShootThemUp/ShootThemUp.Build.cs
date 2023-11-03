// Shoot Them Up Game, All Rights Reserved.

using UnrealBuildTool;

public class ShootThemUp : ModuleRules
{
	public ShootThemUp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{	"Core",
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"Niagara",
			"PhysicsCore",
			"GameplayTasks",
			"NavigationSystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] 
		{ 
			"ShootThemUp/Public/Player",
			"ShootThemUp/Public/Component",
            "ShootThemUp/Public/Dev",
            "ShootThemUp/Public/Weapon",
             "ShootThemUp/Public/UI",
             "ShootThemUp/Public/Pickups",
             "ShootThemUp/Public/Weapon/Components",
             "ShootThemUp/Public/AI",
             "ShootThemUp/Public/AI/Tasks",
             "ShootThemUp/Public/AI/Services",
             "ShootThemUp/Public/AI/EQS",
             "ShootThemUp/Public/AI/Decorators",
			 "ShootThemUp/Public/Menu",
			 "ShootThemUp/Public/Menu/UI"
        });
	}
}
