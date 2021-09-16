#pragma once

#include "Modules/ModuleInterface.h"

class IPoseidonEditor : public IModuleInterface
{
public:
	/** Register and unregister component visualizers used by this module. **/
	virtual void RegisterComponentVisualizers() {}
	virtual void UnregisterComponentVisualizers() {}

	/** Register and unregister detail presenters used by this module. **/
	virtual void RegisterDetails() {}
	virtual void UnregisterDetails() {}

	/** Register and unregister asset type actions. **/
	virtual void RegisterAssetTypeActions() {}
	virtual void UnregisterAssetTypeActions() {}

	/** Create and register / unregister asset brokers. **/
	virtual void RegisterAssetBrokers() {}
	virtual void UnregisterAssetBrokers() {}

	/** Create and register actor factories. **/
	virtual void RegisterActorFactories() {}

	/** Extend menu. **/
	virtual void ExtendMenu() {}

	/** Register and unregister thumbnails. **/
	virtual void RegisterThumbnails() {}
	virtual void UnregisterThumbnails() {}

	/** Register and unregister for undo/redo notifications. **/
	virtual void RegisterForUndo() {}
	virtual void UnregisterForUndo() {}

	/** Create custom modes **/
	virtual void RegisterModes() {}
	virtual void UnregisterModes() {}

	/** Create custom placement extensions */
	virtual void RegisterPlacementModeExtensions() {}
	virtual void UnregisterPlacementModeExtensions() {}
};