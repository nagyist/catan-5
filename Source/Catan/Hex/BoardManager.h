// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <memory>
#include <array>

/**
 * 
 */
class CATAN_API BoardManager
{
public:
	BoardManager();
	~BoardManager();

    void SpawnMap(UWorld* world) const;

private:
    void BuildMap();

    std::array<std::array<std::unique_ptr<FVector2D>, 5>, 5> m_map;
};
