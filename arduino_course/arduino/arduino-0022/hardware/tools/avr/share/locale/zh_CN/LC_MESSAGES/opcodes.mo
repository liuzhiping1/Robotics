??    ^           ?      ?     ?  ?   ?  u   ?  ?   /	  ?   ?	  k   b
  }   ?
  [   L  (   ?     ?     ?     ?     ?          "  	   <  	   F     P     k     ~     ?  (   ?     ?     ?          (     F     c  *   u  
   ?     ?  :   ?  9        <  "   V     y     ?     ?  %   ?  #   ?          #     >     W  .   l  +   ?     ?  !   ?  "     +   &     R     b  "   }     ?     ?  )   ?          $     ?  %   R     x     ?     ?  !   ?     ?     ?     ?          1     L     g  !   ?  !   ?  2   ?  2   ?  2   ,  0   _     ?  $   ?  -   ?  ;      $   <  /   a  	   ?     ?     ?     ?     ?     ?     ?      ?          8  a  K     ?  ?   ?  z   H  ?   ?  ?   \  z   ?  T   p  G   ?  *        8     E     T     c     r     ?     ?     ?     ?     ?     ?     ?  ,        8     P     g  *   ?  *   ?     ?  "   ?  
          E   6  E   |     ?     ?     ?  %        8  '   I  '   q     ?     ?     ?     ?  '     '   ,     T     a     t  #   ?     ?     ?     ?     ?     ?          2     B     X  $   n     ?     ?     ?  !   ?     ?                 *      G      c         %   ?   %   ?   .   ?   .   !  .   E!  ,   t!     ?!  $   ?!  3   ?!  7   "  '   N"  4   v"  	   ?"     ?"     ?"     ?"     ?"     ?"     ?"     #     :#  	   P#     B   8   N   
   D   ;       F   M          G       *      +   =   !   6   7   9   '           J   1   (   	          W                        A          /   .   T   [   3   Q       )           "      2   Y                    \   @                  P   S              K            $              <   5       &      E          ?                      0   #          ]   L   :   ^   R             I   %      Z      U   O              ,   >   -   V   4              X   C   H       
 
  cp0-names=ARCH           Print CP0 register names according to
                           specified architecture.
                           Default: based on binary being disassembled.
 
  fpr-names=ABI            Print FPR names according to specified ABI.
                           Default: numeric.
 
  gpr-names=ABI            Print GPR names according to  specified ABI.
                           Default: based on binary being disassembled.
 
  hwr-names=ARCH           Print HWR names according to specified 
			   architecture.
                           Default: based on binary being disassembled.
 
  reg-names=ABI            Print GPR and FPR names according to
                           specified ABI.
 
  reg-names=ARCH           Print CP0 register and HWR names according to
                           specified architecture.
 
The following ARM specific disassembler options are supported for use with
the -M switch:
 # internal error, undefined modifier(%c) $<undefined> %02x		*unknown* %s: Error:  %s: Warning:  (DP) offset out of range. (SP) offset out of range. (unknown) *unknown* 21-bit offset out of range <function code %d> <illegal precision> <internal disassembler error> <internal error in opcode table: %s %s>
 <unknown register %d> Address 0x%s is out of bounds.
 Bad immediate expression Bad register in postincrement Bad register in preincrement Bad register name Don't know how to specify # dependency %s
 Hmmmm 0x%x Internal disassembler error Internal error:  bad sparc-opcode.h: "%s", %#.8lx, %#.8lx
 Internal error: bad sparc-opcode.h: "%s", %#.8lx, %#.8lx
 Label conflicts with `Rx' Label conflicts with register name Operand is not a symbol Syntax error: No trailing ')' Unknown error %d
 Unrecognised disassembler option: %s
 Unrecognised register name set: %s
 bad instruction `%.50s' bad instruction `%.50s...' branch operand unaligned branch to odd offset branch value not in range and to an odd offset branch value not in range and to odd offset branch value out of range displacement value is not aligned displacement value is out of range don't know how to specify %% dependency %s
 illegal bitmask illegal use of parentheses immediate value cannot be register immediate value is out of range immediate value must be even immediate value not in range and not even immediate value out of range invalid conditional option invalid mask field invalid register for stack adjustment jump hint unaligned junk at end of line missing `)' missing mnemonic in syntax string offset greater than 124 offset greater than 248 offset greater than 62 offset not a multiple of 16 offset not a multiple of 2 offset not a multiple of 4 offset not a multiple of 8 offset not between -2048 and 2047 offset not between -8192 and 8191 operand out of range (%ld not between %ld and %ld) operand out of range (%ld not between %ld and %lu) operand out of range (%lu not between %lu and %lu) operand out of range (%lu not between 0 and %lu) register number must be even source register operand must be even syntax error (expected char `%c', found `%c') syntax error (expected char `%c', found end of instruction) target register operand must be even unable to change directory to "%s", errno = %s
 undefined unknown unknown	0x%02x unknown	0x%04lx unknown	0x%04x unknown constraint `%c' unknown pop reg: %d
 unrecognized form of instruction unrecognized instruction value out of range Project-Id-Version: opcodes 2.15.96
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2005-03-05 20:32+1030
PO-Revision-Date: 2006-01-15 02:10+0800
Last-Translator: Meng Jie <zuxyhere@eastday.com>
Language-Team: Chinese (simplified) <i18n-translation@lists.linux.net.cn>
MIME-Version: 1.0
Content-Type: text/plain; charset=utf-8
Content-Transfer-Encoding: 8bit
 
 
  cp0-names=ARCH           根据指定的架构打印 CP0 寄存器名。
                           默认：根据被反汇编的二进制代码。
 
  fpr-names=ABI            根据指定的 ABI 打印浮点寄存器名。
                           默认：数字。
 
  gpr-names=ABI            根据指定的 ABI 打印通用寄存器名。
                           默认：根据被反汇编的二进制文件。
 
  hwr-names=ARCH           根据指定的架构打印 HWR 寄存器名。
                           默认：根据被反汇编的二进制代码。
 
  reg-names=ABI            根据指定的 ABI 打印通用寄存器和浮点寄存
                           器名。
 
  reg-names=ARCH           根据指定的架构打印 CP0 和 HWR 寄存器名。
 
下列 ARM 特定的反汇编器选项在使用 -M 开关时可用：
 # 内部错误，未定义的修饰符(%c) $<未定义> %02x		*未知* %s：错误： %s：警告： (DP) 偏移量越界 (SP) 偏移量越界。 (未知) *未知* 21位长的偏移量越界 <函数代码 %d> <非法的精度> <反汇编器内部错误> <操作数表中出现内部错误：%s %s>
 <未知的寄存器 %d> 地址 0x%s 越界。
 错误的立即数表达式 后置自增中使用了错误的寄存器 前置自增中使用了错误的寄存器 错误的寄存器名 不知道如何指定 # 依赖 %s
 Hmmmm 0x%x 反汇编器内部错误 内部错误：错误的 sparc-opcode.h：“%s”，%#.8lx，%#.8lx
 内部错误：错误的 sparc-opcode.h：“%s”，%#.8lx，%#.8lx
 标号与‘Rx’冲突 标号与寄存器名冲突 操作数不是一个符号 语法错误：没有结尾的‘)’ 未知错误 %d
 无法识别的反汇编器选项：%s
 无法识别的寄存器名称集：%s
 错误的指令‘%.50s’ 错误的指令‘%.50s...’ 分支操作数未对齐 跳转偏移量为奇数 跳转越界且跳转偏移量为奇数 跳转越界且跳转偏移量为奇数 跳转越界 偏移值未对齐 偏移值越界 不知道如何指定 %% 依赖 %s
 非法的位掩码 括号的使用非法 立即数不能是寄存器 立即数越界 必须给出立即数 立即数越界且不是偶数 立即数越界 无效的条件选项 无效的掩码字段 用于调整堆栈的寄存器无效 跳转提示未对齐 行尾有垃圾字符 缺少‘)’ 语法字符串中没有助记符 偏移量大于 124 偏移量大于 248 偏移量大于 62 偏移量不是 16 的倍数 偏移量不是 2 的倍数 偏移量不是 4 的倍数 偏移量不是 8 的倍数 偏移量不在 -2048 和 2047 之间 偏移量不在 -8192 和 8191 之间 操作数越界(%ld 不在 %ld 和 %ld 之间) 操作数越界(%ld 不在 %ld 和 %lu 之间) 操作数越界(%lu 不在 %lu 和 %lu 之间) 操作数越界(%lu 不在 0 和 %lu 之间) 寄存器数必须是偶数 源寄存器操作数必须是偶数 语法错误(需要字符‘%c’，得到‘%c’) 语法错误(需要字符‘%c’，却到达指令尾) 目的寄存器操作数必须是偶数 无法将当前目录切换至“%s”，errno = %s
 未定义 未知 未知	0x%02x 未知	0x%04lx 未知	0x%04x 未知的约束‘%c’ 未知的弹栈寄存器：%d
 无法识别的指令格式 无法识别的指令 值越界 