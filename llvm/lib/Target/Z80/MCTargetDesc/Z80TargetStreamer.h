//==-- Z80TargetStreamer.h - Z80 Target Streamer -----------------*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file declares Z80-specific target streamer classes.
/// These are for implementing support for target-specific assembly directives.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Z80_MCTARGETDESC_Z80TARGETSTREAMER_H
#define LLVM_LIB_TARGET_Z80_MCTARGETDESC_Z80TARGETSTREAMER_H

#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/Alignment.h"

namespace llvm {
class formatted_raw_ostream;
class MCAsmInfo;

class Z80TargetStreamer : public MCTargetStreamer {
public:
  explicit Z80TargetStreamer(MCStreamer &S);

  virtual void emitAlign(Align Alignment) = 0;
  virtual void emitBlock(uint64_t NumBytes) = 0;
  virtual void emitLocal(MCSymbol *Symbol) = 0;
  virtual void emitWeakGlobal(MCSymbol *Symbol) = 0;
  virtual void emitGlobal(MCSymbol *Symbol) = 0;
  virtual void emitExtern(MCSymbol *Symbol) = 0;
};

class Z80TargetAsmStreamer final : public Z80TargetStreamer {
  const MCAsmInfo *MAI;
  formatted_raw_ostream &OS;

public:
  Z80TargetAsmStreamer(MCStreamer &S, formatted_raw_ostream &OS);

  void emitLabel(MCSymbol *Symbol) override;
  void emitAlign(Align Alignment) override;
  void emitBlock(uint64_t NumBytes) override;
  void emitLocal(MCSymbol *Symbol) override;
  void emitWeakGlobal(MCSymbol *Symbol) override;
  void emitGlobal(MCSymbol *Symbol) override;
  void emitExtern(MCSymbol *Symbol) override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_Z80_MCTARGETDESC_Z80TARGETSTREAMER_H
