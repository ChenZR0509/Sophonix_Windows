#pragma once
/**
 * @file AtomixCli_global
 * @author ChenZR
 */
/* Includes" "------------------------------------------------------------------*/
/* Includes< >------------------------------------------------------------------*/
#include <QtCore/qglobal.h>
/* DataType Definition------------------------------------------------------------------*/
/* Variable Declare------------------------------------------------------------------*/
#if defined(ATOMIXCLI_LIBRARY)
#define ATOMIXCLI_EXPORT Q_DECL_EXPORT
#else
#define ATOMIXCLI_EXPORT Q_DECL_IMPORT
#endif





