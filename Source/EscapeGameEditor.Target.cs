// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class EscapeGameEditorTarget : TargetRules
{
	public EscapeGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        bUseUnityBuild = false;
        bUsePCHFiles = false;

		ExtraModuleNames.AddRange( new string[] { "EscapeGame" } );
	}
}
