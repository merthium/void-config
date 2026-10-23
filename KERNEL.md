# Kernel security snapshot

Observed on 23 October 2026 with the running Void kernel `7.2.11_1`. These are existing kernel settings, not new hardening flags added for this publication.

## Runtime values

| Setting | Observed value |
| --- | --- |
| `kernel.randomize_va_space` | `2` (full userspace ASLR) |
| `kernel.kptr_restrict` | `1` |
| `kernel.dmesg_restrict` | `1` |
| `kernel.yama.ptrace_scope` | `1` |
| `kernel.unprivileged_bpf_disabled` | `1` |
| `fs.protected_hardlinks` | `1` |
| `fs.protected_symlinks` | `1` |

`/sys/kernel/security/lsm` reports `lockdown,capability,landlock,yama`. Registration does not establish an enforced lockdown mode or that applications use Landlock. No AppArmor enforcement claim is made.

The CPU vulnerability report for Spectre v2 reads:

```text
Mitigation: Enhanced / Automatic IBRS; IBPB: conditional; PBRSB-eIBRS: SW sequence; BHI: SW loop, KVM: SW loop
```

Meltdown reports `Not affected` on this processor.

## Kernel build options

The matching `/boot/config-7.2.11_1` has these options set to `y`:

```text
CONFIG_RANDOMIZE_BASE
CONFIG_CPU_MITIGATIONS
CONFIG_SECCOMP
CONFIG_SECCOMP_FILTER
CONFIG_STACKPROTECTOR_STRONG
CONFIG_STRICT_KERNEL_RWX
CONFIG_STRICT_MODULE_RWX
CONFIG_SLAB_FREELIST_RANDOM
CONFIG_SLAB_FREELIST_HARDENED
CONFIG_INIT_ON_ALLOC_DEFAULT_ON
CONFIG_FORTIFY_SOURCE
CONFIG_HARDENED_USERCOPY
CONFIG_SECURITY_DMESG_RESTRICT
CONFIG_X86_UMIP
CONFIG_X86_KERNEL_IBT
```

Build-time support is distinct from runtime enforcement: seccomp, for example, requires a process to install a filter. These are provided by the installed kernel; this repository does not claim authorship of them or a custom kernel build.

## Recheck

```sh
uname -r
sysctl kernel.randomize_va_space kernel.kptr_restrict kernel.dmesg_restrict \
  kernel.yama.ptrace_scope kernel.unprivileged_bpf_disabled \
  fs.protected_hardlinks fs.protected_symlinks
cat /sys/kernel/security/lsm
cat /sys/devices/system/cpu/vulnerabilities/spectre_v2
```

Read access to the LSM list may require root. This snapshot deliberately excludes host identifiers and the full kernel command line. No boot parameters were changed.
