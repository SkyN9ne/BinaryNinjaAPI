#pragma once

#include "binaryninjaapi.h"

// Current ABI version for linking to the UI API. This is incremented any time
// there are changes to the API that affect linking, including new functions,
// new types, modifications to existing functions or types, or new versions
// of the Qt libraries.
#define BN_CURRENT_UI_ABI_VERSION 2

// Minimum ABI version that is supported for loading of plugins. Plugins that
// are linked to an ABI version less than this will not be able to load and
// will require rebuilding. The minimum version is increased when there are
// incompatible changes that break binary compatibility, such as changes to
// existing types or functions, or a new version of Qt.
#define BN_MINIMUM_UI_ABI_VERSION 2

#ifdef __GNUC__
#  ifdef BINARYNINJAUI_LIBRARY
#    define BINARYNINJAUIAPI __attribute__((visibility("default")))
#  else
#    define BINARYNINJAUIAPI
#  endif
#else
#ifdef _MSC_VER
#  ifndef DEMO_VERSION
#   ifdef BINARYNINJAUI_LIBRARY
#     define BINARYNINJAUIAPI __declspec(dllexport)
#   else
#     define BINARYNINJAUIAPI __declspec(dllimport)
#   endif
#  else
#   define BINARYNINJAUIAPI
#  endif
#else
#define BINARYNINJAUIAPI
#endif
#endif

#ifdef BINARYNINJAUI_PYTHON_BINDINGS
#include "bindings.h"
#endif

// The BN_DECLARE_UI_ABI_VERSION must be included in native UI plugin modules. If
// the ABI version is not declared, the UI will not load the plugin.
#ifdef DEMO_VERSION
#define BN_DECLARE_UI_ABI_VERSION
#else
#define BN_DECLARE_UI_ABI_VERSION \
	extern "C" \
	{ \
		BINARYNINJAPLUGIN uint32_t UIPluginABIVersion() \
		{ \
			return BN_CURRENT_UI_ABI_VERSION; \
		} \
	}
#endif

// The Python bindings generator does not recognize automatic conversion of API types into their
// Python equivalents if using templates (Ref<*>), so we typedef all API references so that
// the Python bindings can be easily generated for them.
typedef BinaryNinja::Ref<BinaryNinja::Architecture> ArchitectureRef;
typedef BinaryNinja::Ref<BinaryNinja::BackgroundTask> BackgroundTaskRef;
typedef BinaryNinja::Ref<BinaryNinja::BasicBlock> BasicBlockRef;
typedef BinaryNinja::Ref<BinaryNinja::BinaryData> BinaryDataRef;
typedef BinaryNinja::Ref<BinaryNinja::BinaryView> BinaryViewRef;
typedef BinaryNinja::Ref<BinaryNinja::BinaryViewType> BinaryViewTypeRef;
typedef BinaryNinja::Ref<BinaryNinja::DisassemblySettings> DisassemblySettingsRef;
typedef BinaryNinja::Ref<BinaryNinja::DownloadProvider> DownloadProviderRef;
typedef BinaryNinja::Ref<BinaryNinja::Enumeration> EnumerationRef;
typedef BinaryNinja::Ref<BinaryNinja::FileMetadata> FileMetadataRef;
typedef BinaryNinja::Ref<BinaryNinja::FlowGraph> FlowGraphRef;
typedef BinaryNinja::Ref<BinaryNinja::FlowGraphLayoutRequest> FlowGraphLayoutRequestRef;
typedef BinaryNinja::Ref<BinaryNinja::FlowGraphNode> FlowGraphNodeRef;
typedef BinaryNinja::Ref<BinaryNinja::Function> FunctionRef;
typedef BinaryNinja::Ref<BinaryNinja::LowLevelILFunction> LowLevelILFunctionRef;
typedef BinaryNinja::Ref<BinaryNinja::MainThreadAction> MainThreadActionRef;
typedef BinaryNinja::Ref<BinaryNinja::MediumLevelILFunction> MediumLevelILFunctionRef;
typedef BinaryNinja::Ref<BinaryNinja::HighLevelILFunction> HighLevelILFunctionRef;
typedef BinaryNinja::Ref<BinaryNinja::Platform> PlatformRef;
typedef BinaryNinja::Ref<BinaryNinja::ReportCollection> ReportCollectionRef;
typedef BinaryNinja::Ref<BinaryNinja::SaveSettings> SaveSettingsRef;
typedef BinaryNinja::Ref<BinaryNinja::ScriptingInstance> ScriptingInstanceRef;
typedef BinaryNinja::Ref<BinaryNinja::ScriptingProvider> ScriptingProviderRef;
typedef BinaryNinja::Ref<BinaryNinja::Section> SectionRef;
typedef BinaryNinja::Ref<BinaryNinja::Segment> SegmentRef;
typedef BinaryNinja::Ref<BinaryNinja::Settings> SettingsRef;
typedef BinaryNinja::Ref<BinaryNinja::Structure> StructureRef;
typedef BinaryNinja::Ref<BinaryNinja::Symbol> SymbolRef;
typedef BinaryNinja::Ref<BinaryNinja::Tag> TagRef;
typedef BinaryNinja::Ref<BinaryNinja::TagType> TagTypeRef;
typedef BinaryNinja::Ref<BinaryNinja::TemporaryFile> TemporaryFileRef;
typedef BinaryNinja::Ref<BinaryNinja::Transform> TransformRef;
typedef BinaryNinja::Ref<BinaryNinja::Type> TypeRef;
typedef BinaryNinja::Ref<BinaryNinja::RepoPlugin> RepoPluginRef;
typedef BinaryNinja::Ref<BinaryNinja::Repository> RepositoryRef;
typedef BinaryNinja::Ref<BinaryNinja::RepositoryManager> RepositoryManagerRef;
