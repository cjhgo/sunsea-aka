
gobang:     file format elf32-i386


Disassembly of section .interp:

08048134 <.interp>:
 8048134:	2f                   	das    
 8048135:	6c                   	insb   (%dx),%es:(%edi)
 8048136:	69 62 2f 6c 64 2d 6c 	imul   $0x6c2d646c,0x2f(%edx),%esp
 804813d:	69 6e 75 78 2e 73 6f 	imul   $0x6f732e78,0x75(%esi),%ebp
 8048144:	2e 32 00             	xor    %cs:(%eax),%al

Disassembly of section .note.ABI-tag:

08048148 <.note.ABI-tag>:
 8048148:	04 00                	add    $0x0,%al
 804814a:	00 00                	add    %al,(%eax)
 804814c:	10 00                	adc    %al,(%eax)
 804814e:	00 00                	add    %al,(%eax)
 8048150:	01 00                	add    %eax,(%eax)
 8048152:	00 00                	add    %al,(%eax)
 8048154:	47                   	inc    %edi
 8048155:	4e                   	dec    %esi
 8048156:	55                   	push   %ebp
 8048157:	00 00                	add    %al,(%eax)
 8048159:	00 00                	add    %al,(%eax)
 804815b:	00 02                	add    %al,(%edx)
 804815d:	00 00                	add    %al,(%eax)
 804815f:	00 06                	add    %al,(%esi)
 8048161:	00 00                	add    %al,(%eax)
 8048163:	00 0f                	add    %cl,(%edi)
 8048165:	00 00                	add    %al,(%eax)
	...

Disassembly of section .note.gnu.build-id:

08048168 <.note.gnu.build-id>:
 8048168:	04 00                	add    $0x0,%al
 804816a:	00 00                	add    %al,(%eax)
 804816c:	14 00                	adc    $0x0,%al
 804816e:	00 00                	add    %al,(%eax)
 8048170:	03 00                	add    (%eax),%eax
 8048172:	00 00                	add    %al,(%eax)
 8048174:	47                   	inc    %edi
 8048175:	4e                   	dec    %esi
 8048176:	55                   	push   %ebp
 8048177:	00 20                	add    %ah,(%eax)
 8048179:	0c 61                	or     $0x61,%al
 804817b:	fc                   	cld    
 804817c:	21 2d 28 56 56 e9    	and    %ebp,0xe9565628
 8048182:	00 d1                	add    %dl,%cl
 8048184:	87 4d 39             	xchg   %ecx,0x39(%ebp)
 8048187:	7c c7                	jl     8048150 <_init-0x2fc>
 8048189:	c8                   	.byte 0xc8
 804818a:	8a 26                	mov    (%esi),%ah

Disassembly of section .hash:

0804818c <.hash>:
 804818c:	03 00                	add    (%eax),%eax
 804818e:	00 00                	add    %al,(%eax)
 8048190:	0f 00 00             	sldt   (%eax)
 8048193:	00 0c 00             	add    %cl,(%eax,%eax,1)
 8048196:	00 00                	add    %al,(%eax)
 8048198:	0d 00 00 00 0a       	or     $0xa000000,%eax
	...
 80481ad:	00 00                	add    %al,(%eax)
 80481af:	00 03                	add    %al,(%ebx)
 80481b1:	00 00                	add    %al,(%eax)
 80481b3:	00 04 00             	add    %al,(%eax,%eax,1)
 80481b6:	00 00                	add    %al,(%eax)
 80481b8:	02 00                	add    (%eax),%al
 80481ba:	00 00                	add    %al,(%eax)
 80481bc:	06                   	push   %es
 80481bd:	00 00                	add    %al,(%eax)
 80481bf:	00 0e                	add    %cl,(%esi)
 80481c1:	00 00                	add    %al,(%eax)
 80481c3:	00 07                	add    %al,(%edi)
 80481c5:	00 00                	add    %al,(%eax)
 80481c7:	00 08                	add    %cl,(%eax)
 80481c9:	00 00                	add    %al,(%eax)
 80481cb:	00 09                	add    %cl,(%ecx)
 80481cd:	00 00                	add    %al,(%eax)
 80481cf:	00 05 00 00 00 0b    	add    %al,0xb000000
 80481d5:	00 00                	add    %al,(%eax)
 80481d7:	00 01                	add    %al,(%ecx)
 80481d9:	00 00                	add    %al,(%eax)
	...

Disassembly of section .gnu.hash:

080481dc <.gnu.hash>:
 80481dc:	02 00                	add    (%eax),%al
 80481de:	00 00                	add    %al,(%eax)
 80481e0:	0e                   	push   %cs
 80481e1:	00 00                	add    %al,(%eax)
 80481e3:	00 01                	add    %al,(%ecx)
 80481e5:	00 00                	add    %al,(%eax)
 80481e7:	00 05 00 00 00 00    	add    %al,0x0
 80481ed:	20 00                	and    %al,(%eax)
 80481ef:	20 00                	and    %al,(%eax)
 80481f1:	00 00                	add    %al,(%eax)
 80481f3:	00 0e                	add    %cl,(%esi)
 80481f5:	00 00                	add    %al,(%eax)
 80481f7:	00                   	.byte 0x0
 80481f8:	ad                   	lods   %ds:(%esi),%eax
 80481f9:	4b                   	dec    %ebx
 80481fa:	e3 c0                	jecxz  80481bc <_init-0x290>

Disassembly of section .dynsym:

080481fc <.dynsym>:
	...
 804820c:	77 00                	ja     804820e <_init-0x23e>
	...
 8048216:	00 00                	add    %al,(%eax)
 8048218:	12 00                	adc    (%eax),%al
 804821a:	00 00                	add    %al,(%eax)
 804821c:	60                   	pusha  
	...
 8048225:	00 00                	add    %al,(%eax)
 8048227:	00 12                	add    %dl,(%edx)
 8048229:	00 00                	add    %al,(%eax)
 804822b:	00 0b                	add    %cl,(%ebx)
	...
 8048235:	00 00                	add    %al,(%eax)
 8048237:	00 20                	add    %ah,(%eax)
 8048239:	00 00                	add    %al,(%eax)
 804823b:	00 1a                	add    %bl,(%edx)
	...
 8048245:	00 00                	add    %al,(%eax)
 8048247:	00 20                	add    %ah,(%eax)
 8048249:	00 00                	add    %al,(%eax)
 804824b:	00 65 00             	add    %ah,0x0(%ebp)
	...
 8048256:	00 00                	add    %al,(%eax)
 8048258:	12 00                	adc    (%eax),%al
 804825a:	00 00                	add    %al,(%eax)
 804825c:	7c 00                	jl     804825e <_init-0x1ee>
	...
 8048266:	00 00                	add    %al,(%eax)
 8048268:	12 00                	adc    (%eax),%al
 804826a:	00 00                	add    %al,(%eax)
 804826c:	6c                   	insb   (%dx),%es:(%edi)
	...
 8048275:	00 00                	add    %al,(%eax)
 8048277:	00 12                	add    %dl,(%edx)
 8048279:	00 00                	add    %al,(%eax)
 804827b:	00 71 00             	add    %dh,0x0(%ecx)
	...
 8048286:	00 00                	add    %al,(%eax)
 8048288:	12 00                	adc    (%eax),%al
 804828a:	00 00                	add    %al,(%eax)
 804828c:	32 00                	xor    (%eax),%al
	...
 8048296:	00 00                	add    %al,(%eax)
 8048298:	12 00                	adc    (%eax),%al
 804829a:	00 00                	add    %al,(%eax)
 804829c:	59                   	pop    %ecx
	...
 80482a5:	00 00                	add    %al,(%eax)
 80482a7:	00 12                	add    %dl,(%edx)
 80482a9:	00 00                	add    %al,(%eax)
 80482ab:	00 54 00 00          	add    %dl,0x0(%eax,%eax,1)
	...
 80482b7:	00 12                	add    %dl,(%edx)
 80482b9:	00 00                	add    %al,(%eax)
 80482bb:	00 2e                	add    %ch,(%esi)
	...
 80482c5:	00 00                	add    %al,(%eax)
 80482c7:	00 12                	add    %dl,(%edx)
 80482c9:	00 00                	add    %al,(%eax)
 80482cb:	00 4f 00             	add    %cl,0x0(%edi)
	...
 80482d6:	00 00                	add    %al,(%eax)
 80482d8:	12 00                	adc    (%eax),%al
 80482da:	00 00                	add    %al,(%eax)
 80482dc:	40                   	inc    %eax
 80482dd:	00 00                	add    %al,(%eax)
 80482df:	00 2c a4             	add    %ch,(%esp,%eiz,4)
 80482e2:	04 08                	add    $0x8,%al
 80482e4:	04 00                	add    $0x0,%al
 80482e6:	00 00                	add    %al,(%eax)
 80482e8:	11 00                	adc    %eax,(%eax)
 80482ea:	10 00                	adc    %al,(%eax)

Disassembly of section .dynstr:

080482ec <.dynstr>:
 80482ec:	00 6c 69 62          	add    %ch,0x62(%ecx,%ebp,2)
 80482f0:	6d                   	insl   (%dx),%es:(%edi)
 80482f1:	2e 73 6f             	jae,pn 8048363 <_init-0xe9>
 80482f4:	2e 36 00 5f 5f       	add    %bl,%cs:%ss:0x5f(%edi)
 80482f9:	67 6d                	addr16 insl (%dx),%es:(%di)
 80482fb:	6f                   	outsl  %ds:(%esi),(%dx)
 80482fc:	6e                   	outsb  %ds:(%esi),(%dx)
 80482fd:	5f                   	pop    %edi
 80482fe:	73 74                	jae    8048374 <_init-0xd8>
 8048300:	61                   	popa   
 8048301:	72 74                	jb     8048377 <_init-0xd5>
 8048303:	5f                   	pop    %edi
 8048304:	5f                   	pop    %edi
 8048305:	00 5f 4a             	add    %bl,0x4a(%edi)
 8048308:	76 5f                	jbe    8048369 <_init-0xe3>
 804830a:	52                   	push   %edx
 804830b:	65 67 69 73 74 65 72 	addr16 imul $0x6c437265,%gs:0x74(%bp,%di),%esi
 8048312:	43 6c 
 8048314:	61                   	popa   
 8048315:	73 73                	jae    804838a <_init-0xc2>
 8048317:	65                   	gs
 8048318:	73 00                	jae    804831a <_init-0x132>
 804831a:	73 69                	jae    8048385 <_init-0xc7>
 804831c:	6e                   	outsb  %ds:(%esi),(%dx)
 804831d:	00 63 6f             	add    %ah,0x6f(%ebx)
 8048320:	73 00                	jae    8048322 <_init-0x12a>
 8048322:	6c                   	insb   (%dx),%es:(%edi)
 8048323:	69 62 63 2e 73 6f 2e 	imul   $0x2e6f732e,0x63(%edx),%esp
 804832a:	36 00 5f 49          	add    %bl,%ss:0x49(%edi)
 804832e:	4f                   	dec    %edi
 804832f:	5f                   	pop    %edi
 8048330:	73 74                	jae    80483a6 <_init-0xa6>
 8048332:	64 69 6e 5f 75 73 65 	imul   $0x64657375,%fs:0x5f(%esi),%ebp
 8048339:	64 
 804833a:	00 65 78             	add    %ah,0x78(%ebp)
 804833d:	69 74 00 70 75 74 73 	imul   $0x737475,0x70(%eax,%eax,1),%esi
 8048344:	00 
 8048345:	70 72                	jo     80483b9 <_init-0x93>
 8048347:	69 6e 74 66 00 6d 6d 	imul   $0x6d6d0066,0x74(%esi),%ebp
 804834e:	61                   	popa   
 804834f:	70 00                	jo     8048351 <_init-0xfb>
 8048351:	6d                   	insl   (%dx),%es:(%edi)
 8048352:	65                   	gs
 8048353:	6d                   	insl   (%dx),%es:(%edi)
 8048354:	73 65                	jae    80483bb <_init-0x91>
 8048356:	74 00                	je     8048358 <_init-0xf4>
 8048358:	72 65                	jb     80483bf <_init-0x8d>
 804835a:	61                   	popa   
 804835b:	64 00 69 6f          	add    %ch,%fs:0x6f(%ecx)
 804835f:	63 74 6c 00          	arpl   %si,0x0(%esp,%ebp,2)
 8048363:	6f                   	outsl  %ds:(%esi),(%dx)
 8048364:	70 65                	jo     80483cb <_init-0x81>
 8048366:	6e                   	outsb  %ds:(%esi),(%dx)
 8048367:	00 5f 5f             	add    %bl,0x5f(%edi)
 804836a:	6c                   	insb   (%dx),%es:(%edi)
 804836b:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%edx),%esp
 8048372:	72 74                	jb     80483e8 <_init-0x64>
 8048374:	5f                   	pop    %edi
 8048375:	6d                   	insl   (%dx),%es:(%edi)
 8048376:	61                   	popa   
 8048377:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%esi),%ebp
 804837e:	43                   	inc    %ebx
 804837f:	5f                   	pop    %edi
 8048380:	32 2e                	xor    (%esi),%ch
 8048382:	30 00                	xor    %al,(%eax)

Disassembly of section .gnu.version:

08048384 <.gnu.version>:
 8048384:	00 00                	add    %al,(%eax)
 8048386:	02 00                	add    (%eax),%al
 8048388:	02 00                	add    (%eax),%al
 804838a:	00 00                	add    %al,(%eax)
 804838c:	00 00                	add    %al,(%eax)
 804838e:	02 00                	add    (%eax),%al
 8048390:	02 00                	add    (%eax),%al
 8048392:	02 00                	add    (%eax),%al
 8048394:	02 00                	add    (%eax),%al
 8048396:	03 00                	add    (%eax),%eax
 8048398:	02 00                	add    (%eax),%al
 804839a:	02 00                	add    (%eax),%al
 804839c:	03 00                	add    (%eax),%eax
 804839e:	02 00                	add    (%eax),%al
 80483a0:	01 00                	add    %eax,(%eax)

Disassembly of section .gnu.version_r:

080483a4 <.gnu.version_r>:
 80483a4:	01 00                	add    %eax,(%eax)
 80483a6:	01 00                	add    %eax,(%eax)
 80483a8:	01 00                	add    %eax,(%eax)
 80483aa:	00 00                	add    %al,(%eax)
 80483ac:	10 00                	adc    %al,(%eax)
 80483ae:	00 00                	add    %al,(%eax)
 80483b0:	20 00                	and    %al,(%eax)
 80483b2:	00 00                	add    %al,(%eax)
 80483b4:	10 69 69             	adc    %ch,0x69(%ecx)
 80483b7:	0d 00 00 03 00       	or     $0x30000,%eax
 80483bc:	8e 00                	mov    (%eax),%es
 80483be:	00 00                	add    %al,(%eax)
 80483c0:	00 00                	add    %al,(%eax)
 80483c2:	00 00                	add    %al,(%eax)
 80483c4:	01 00                	add    %eax,(%eax)
 80483c6:	01 00                	add    %eax,(%eax)
 80483c8:	36 00 00             	add    %al,%ss:(%eax)
 80483cb:	00 10                	add    %dl,(%eax)
 80483cd:	00 00                	add    %al,(%eax)
 80483cf:	00 00                	add    %al,(%eax)
 80483d1:	00 00                	add    %al,(%eax)
 80483d3:	00 10                	add    %dl,(%eax)
 80483d5:	69 69 0d 00 00 02 00 	imul   $0x20000,0xd(%ecx),%ebp
 80483dc:	8e 00                	mov    (%eax),%es
 80483de:	00 00                	add    %al,(%eax)
 80483e0:	00 00                	add    %al,(%eax)
	...

Disassembly of section .rel.dyn:

080483e4 <.rel.dyn>:
 80483e4:	f0 bf 04 08 06 03    	lock mov $0x3060804,%edi
	...

Disassembly of section .rel.plt:

080483ec <.rel.plt>:
 80483ec:	00 c0                	add    %al,%al
 80483ee:	04 08                	add    $0x8,%al
 80483f0:	07                   	pop    %es
 80483f1:	01 00                	add    %eax,(%eax)
 80483f3:	00 04 c0             	add    %al,(%eax,%eax,8)
 80483f6:	04 08                	add    $0x8,%al
 80483f8:	07                   	pop    %es
 80483f9:	02 00                	add    (%eax),%al
 80483fb:	00 08                	add    %cl,(%eax)
 80483fd:	c0 04 08 07          	rolb   $0x7,(%eax,%ecx,1)
 8048401:	03 00                	add    (%eax),%eax
 8048403:	00 0c c0             	add    %cl,(%eax,%eax,8)
 8048406:	04 08                	add    $0x8,%al
 8048408:	07                   	pop    %es
 8048409:	05 00 00 10 c0       	add    $0xc0100000,%eax
 804840e:	04 08                	add    $0x8,%al
 8048410:	07                   	pop    %es
 8048411:	06                   	push   %es
 8048412:	00 00                	add    %al,(%eax)
 8048414:	14 c0                	adc    $0xc0,%al
 8048416:	04 08                	add    $0x8,%al
 8048418:	07                   	pop    %es
 8048419:	07                   	pop    %es
 804841a:	00 00                	add    %al,(%eax)
 804841c:	18 c0                	sbb    %al,%al
 804841e:	04 08                	add    $0x8,%al
 8048420:	07                   	pop    %es
 8048421:	08 00                	or     %al,(%eax)
 8048423:	00 1c c0             	add    %bl,(%eax,%eax,8)
 8048426:	04 08                	add    $0x8,%al
 8048428:	07                   	pop    %es
 8048429:	09 00                	or     %eax,(%eax)
 804842b:	00 20                	add    %ah,(%eax)
 804842d:	c0 04 08 07          	rolb   $0x7,(%eax,%ecx,1)
 8048431:	0a 00                	or     (%eax),%al
 8048433:	00 24 c0             	add    %ah,(%eax,%eax,8)
 8048436:	04 08                	add    $0x8,%al
 8048438:	07                   	pop    %es
 8048439:	0b 00                	or     (%eax),%eax
 804843b:	00 28                	add    %ch,(%eax)
 804843d:	c0 04 08 07          	rolb   $0x7,(%eax,%ecx,1)
 8048441:	0c 00                	or     $0x0,%al
 8048443:	00 2c c0             	add    %ch,(%eax,%eax,8)
 8048446:	04 08                	add    $0x8,%al
 8048448:	07                   	pop    %es
 8048449:	0d                   	.byte 0xd
	...

Disassembly of section .init:

0804844c <_init>:
 804844c:	55                   	push   %ebp
 804844d:	89 e5                	mov    %esp,%ebp
 804844f:	53                   	push   %ebx
 8048450:	83 ec 04             	sub    $0x4,%esp
 8048453:	e8 00 00 00 00       	call   8048458 <_init+0xc>
 8048458:	5b                   	pop    %ebx
 8048459:	81 c3 9c 3b 00 00    	add    $0x3b9c,%ebx
 804845f:	8b 93 fc ff ff ff    	mov    -0x4(%ebx),%edx
 8048465:	85 d2                	test   %edx,%edx
 8048467:	74 05                	je     804846e <_init+0x22>
 8048469:	e8 3e 00 00 00       	call   80484ac <__gmon_start__@plt>
 804846e:	e8 6d 01 00 00       	call   80485e0 <frame_dummy>
 8048473:	e8 68 1f 00 00       	call   804a3e0 <__do_global_ctors_aux>
 8048478:	58                   	pop    %eax
 8048479:	5b                   	pop    %ebx
 804847a:	c9                   	leave  
 804847b:	c3                   	ret    

Disassembly of section .plt:

0804847c <open@plt-0x10>:
 804847c:	ff 35 f8 bf 04 08    	pushl  0x804bff8
 8048482:	ff 25 fc bf 04 08    	jmp    *0x804bffc
 8048488:	00 00                	add    %al,(%eax)
	...

0804848c <open@plt>:
 804848c:	ff 25 00 c0 04 08    	jmp    *0x804c000
 8048492:	68 00 00 00 00       	push   $0x0
 8048497:	e9 e0 ff ff ff       	jmp    804847c <_init+0x30>

0804849c <mmap@plt>:
 804849c:	ff 25 04 c0 04 08    	jmp    *0x804c004
 80484a2:	68 08 00 00 00       	push   $0x8
 80484a7:	e9 d0 ff ff ff       	jmp    804847c <_init+0x30>

080484ac <__gmon_start__@plt>:
 80484ac:	ff 25 08 c0 04 08    	jmp    *0x804c008
 80484b2:	68 10 00 00 00       	push   $0x10
 80484b7:	e9 c0 ff ff ff       	jmp    804847c <_init+0x30>

080484bc <memset@plt>:
 80484bc:	ff 25 0c c0 04 08    	jmp    *0x804c00c
 80484c2:	68 18 00 00 00       	push   $0x18
 80484c7:	e9 b0 ff ff ff       	jmp    804847c <_init+0x30>

080484cc <__libc_start_main@plt>:
 80484cc:	ff 25 10 c0 04 08    	jmp    *0x804c010
 80484d2:	68 20 00 00 00       	push   $0x20
 80484d7:	e9 a0 ff ff ff       	jmp    804847c <_init+0x30>

080484dc <read@plt>:
 80484dc:	ff 25 14 c0 04 08    	jmp    *0x804c014
 80484e2:	68 28 00 00 00       	push   $0x28
 80484e7:	e9 90 ff ff ff       	jmp    804847c <_init+0x30>

080484ec <ioctl@plt>:
 80484ec:	ff 25 18 c0 04 08    	jmp    *0x804c018
 80484f2:	68 30 00 00 00       	push   $0x30
 80484f7:	e9 80 ff ff ff       	jmp    804847c <_init+0x30>

080484fc <cos@plt>:
 80484fc:	ff 25 1c c0 04 08    	jmp    *0x804c01c
 8048502:	68 38 00 00 00       	push   $0x38
 8048507:	e9 70 ff ff ff       	jmp    804847c <_init+0x30>

0804850c <printf@plt>:
 804850c:	ff 25 20 c0 04 08    	jmp    *0x804c020
 8048512:	68 40 00 00 00       	push   $0x40
 8048517:	e9 60 ff ff ff       	jmp    804847c <_init+0x30>

0804851c <puts@plt>:
 804851c:	ff 25 24 c0 04 08    	jmp    *0x804c024
 8048522:	68 48 00 00 00       	push   $0x48
 8048527:	e9 50 ff ff ff       	jmp    804847c <_init+0x30>

0804852c <sin@plt>:
 804852c:	ff 25 28 c0 04 08    	jmp    *0x804c028
 8048532:	68 50 00 00 00       	push   $0x50
 8048537:	e9 40 ff ff ff       	jmp    804847c <_init+0x30>

0804853c <exit@plt>:
 804853c:	ff 25 2c c0 04 08    	jmp    *0x804c02c
 8048542:	68 58 00 00 00       	push   $0x58
 8048547:	e9 30 ff ff ff       	jmp    804847c <_init+0x30>

Disassembly of section .text:

08048550 <_start>:
 8048550:	31 ed                	xor    %ebp,%ebp
 8048552:	5e                   	pop    %esi
 8048553:	89 e1                	mov    %esp,%ecx
 8048555:	83 e4 f0             	and    $0xfffffff0,%esp
 8048558:	50                   	push   %eax
 8048559:	54                   	push   %esp
 804855a:	52                   	push   %edx
 804855b:	68 70 a3 04 08       	push   $0x804a370
 8048560:	68 80 a3 04 08       	push   $0x804a380
 8048565:	51                   	push   %ecx
 8048566:	56                   	push   %esi
 8048567:	68 54 9b 04 08       	push   $0x8049b54
 804856c:	e8 5b ff ff ff       	call   80484cc <__libc_start_main@plt>
 8048571:	f4                   	hlt    
 8048572:	90                   	nop
 8048573:	90                   	nop
 8048574:	90                   	nop
 8048575:	90                   	nop
 8048576:	90                   	nop
 8048577:	90                   	nop
 8048578:	90                   	nop
 8048579:	90                   	nop
 804857a:	90                   	nop
 804857b:	90                   	nop
 804857c:	90                   	nop
 804857d:	90                   	nop
 804857e:	90                   	nop
 804857f:	90                   	nop

08048580 <__do_global_dtors_aux>:
 8048580:	55                   	push   %ebp
 8048581:	89 e5                	mov    %esp,%ebp
 8048583:	53                   	push   %ebx
 8048584:	83 ec 04             	sub    $0x4,%esp
 8048587:	80 3d 60 c4 04 08 00 	cmpb   $0x0,0x804c460
 804858e:	75 3f                	jne    80485cf <__do_global_dtors_aux+0x4f>
 8048590:	a1 64 c4 04 08       	mov    0x804c464,%eax
 8048595:	bb 10 bf 04 08       	mov    $0x804bf10,%ebx
 804859a:	81 eb 0c bf 04 08    	sub    $0x804bf0c,%ebx
 80485a0:	c1 fb 02             	sar    $0x2,%ebx
 80485a3:	83 eb 01             	sub    $0x1,%ebx
 80485a6:	39 d8                	cmp    %ebx,%eax
 80485a8:	73 1e                	jae    80485c8 <__do_global_dtors_aux+0x48>
 80485aa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 80485b0:	83 c0 01             	add    $0x1,%eax
 80485b3:	a3 64 c4 04 08       	mov    %eax,0x804c464
 80485b8:	ff 14 85 0c bf 04 08 	call   *0x804bf0c(,%eax,4)
 80485bf:	a1 64 c4 04 08       	mov    0x804c464,%eax
 80485c4:	39 d8                	cmp    %ebx,%eax
 80485c6:	72 e8                	jb     80485b0 <__do_global_dtors_aux+0x30>
 80485c8:	c6 05 60 c4 04 08 01 	movb   $0x1,0x804c460
 80485cf:	83 c4 04             	add    $0x4,%esp
 80485d2:	5b                   	pop    %ebx
 80485d3:	5d                   	pop    %ebp
 80485d4:	c3                   	ret    
 80485d5:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80485d9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080485e0 <frame_dummy>:
 80485e0:	55                   	push   %ebp
 80485e1:	89 e5                	mov    %esp,%ebp
 80485e3:	83 ec 18             	sub    $0x18,%esp
 80485e6:	a1 14 bf 04 08       	mov    0x804bf14,%eax
 80485eb:	85 c0                	test   %eax,%eax
 80485ed:	74 12                	je     8048601 <frame_dummy+0x21>
 80485ef:	b8 00 00 00 00       	mov    $0x0,%eax
 80485f4:	85 c0                	test   %eax,%eax
 80485f6:	74 09                	je     8048601 <frame_dummy+0x21>
 80485f8:	c7 04 24 14 bf 04 08 	movl   $0x804bf14,(%esp)
 80485ff:	ff d0                	call   *%eax
 8048601:	c9                   	leave  
 8048602:	c3                   	ret    
 8048603:	90                   	nop

08048604 <computer>:
 8048604:	55                   	push   %ebp
 8048605:	89 e5                	mov    %esp,%ebp
 8048607:	83 ec 28             	sub    $0x28,%esp
 804860a:	e8 ac 0e 00 00       	call   80494bb <get_player_win_table_max>
 804860f:	e8 f3 11 00 00       	call   8049807 <get_computer_win_table_max>
 8048614:	8b 0d 88 d6 04 08    	mov    0x804d688,%ecx
 804861a:	8b 15 84 d6 04 08    	mov    0x804d684,%edx
 8048620:	b8 30 a4 04 08       	mov    $0x804a430,%eax
 8048625:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 8048629:	89 54 24 04          	mov    %edx,0x4(%esp)
 804862d:	89 04 24             	mov    %eax,(%esp)
 8048630:	e8 d7 fe ff ff       	call   804850c <printf@plt>
 8048635:	8b 0d 90 d6 04 08    	mov    0x804d690,%ecx
 804863b:	8b 15 8c d6 04 08    	mov    0x804d68c,%edx
 8048641:	b8 45 a4 04 08       	mov    $0x804a445,%eax
 8048646:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 804864a:	89 54 24 04          	mov    %edx,0x4(%esp)
 804864e:	89 04 24             	mov    %eax,(%esp)
 8048651:	e8 b6 fe ff ff       	call   804850c <printf@plt>
 8048656:	8b 15 00 d7 04 08    	mov    0x804d700,%edx
 804865c:	a1 e0 d6 04 08       	mov    0x804d6e0,%eax
 8048661:	39 c2                	cmp    %eax,%edx
 8048663:	0f 8c 96 00 00 00    	jl     80486ff <computer+0xfb>
 8048669:	a1 8c d6 04 08       	mov    0x804d68c,%eax
 804866e:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048671:	a1 90 d6 04 08       	mov    0x804d690,%eax
 8048676:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8048679:	8b 55 f4             	mov    -0xc(%ebp),%edx
 804867c:	8b 4d f0             	mov    -0x10(%ebp),%ecx
 804867f:	89 d0                	mov    %edx,%eax
 8048681:	c1 e0 04             	shl    $0x4,%eax
 8048684:	29 d0                	sub    %edx,%eax
 8048686:	01 c8                	add    %ecx,%eax
 8048688:	c7 04 85 80 c4 04 08 	movl   $0x2,0x804c480(,%eax,4)
 804868f:	02 00 00 00 
 8048693:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048696:	89 d0                	mov    %edx,%eax
 8048698:	c1 e0 02             	shl    $0x2,%eax
 804869b:	01 d0                	add    %edx,%eax
 804869d:	c1 e0 03             	shl    $0x3,%eax
 80486a0:	05 8a 02 00 00       	add    $0x28a,%eax
 80486a5:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80486a8:	8b 55 f0             	mov    -0x10(%ebp),%edx
 80486ab:	89 d0                	mov    %edx,%eax
 80486ad:	c1 e0 02             	shl    $0x2,%eax
 80486b0:	01 d0                	add    %edx,%eax
 80486b2:	c1 e0 03             	shl    $0x3,%eax
 80486b5:	83 c0 64             	add    $0x64,%eax
 80486b8:	89 45 f0             	mov    %eax,-0x10(%ebp)
 80486bb:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80486be:	89 44 24 04          	mov    %eax,0x4(%esp)
 80486c2:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80486c5:	89 04 24             	mov    %eax,(%esp)
 80486c8:	e8 16 02 00 00       	call   80488e3 <fb_black_point>
 80486cd:	a1 60 c0 04 08       	mov    0x804c060,%eax
 80486d2:	89 c2                	mov    %eax,%edx
 80486d4:	83 c0 01             	add    $0x1,%eax
 80486d7:	a3 60 c0 04 08       	mov    %eax,0x804c060
 80486dc:	c7 44 24 0c ff ff ff 	movl   $0xffffff,0xc(%esp)
 80486e3:	00 
 80486e4:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80486e7:	89 44 24 08          	mov    %eax,0x8(%esp)
 80486eb:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80486ee:	89 44 24 04          	mov    %eax,0x4(%esp)
 80486f2:	89 14 24             	mov    %edx,(%esp)
 80486f5:	e8 66 03 00 00       	call   8048a60 <fb_num>
 80486fa:	e9 91 00 00 00       	jmp    8048790 <computer+0x18c>
 80486ff:	a1 84 d6 04 08       	mov    0x804d684,%eax
 8048704:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8048707:	a1 88 d6 04 08       	mov    0x804d688,%eax
 804870c:	89 45 f0             	mov    %eax,-0x10(%ebp)
 804870f:	8b 55 f4             	mov    -0xc(%ebp),%edx
 8048712:	8b 4d f0             	mov    -0x10(%ebp),%ecx
 8048715:	89 d0                	mov    %edx,%eax
 8048717:	c1 e0 04             	shl    $0x4,%eax
 804871a:	29 d0                	sub    %edx,%eax
 804871c:	01 c8                	add    %ecx,%eax
 804871e:	c7 04 85 80 c4 04 08 	movl   $0x2,0x804c480(,%eax,4)
 8048725:	02 00 00 00 
 8048729:	8b 55 f4             	mov    -0xc(%ebp),%edx
 804872c:	89 d0                	mov    %edx,%eax
 804872e:	c1 e0 02             	shl    $0x2,%eax
 8048731:	01 d0                	add    %edx,%eax
 8048733:	c1 e0 03             	shl    $0x3,%eax
 8048736:	05 8a 02 00 00       	add    $0x28a,%eax
 804873b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804873e:	8b 55 f0             	mov    -0x10(%ebp),%edx
 8048741:	89 d0                	mov    %edx,%eax
 8048743:	c1 e0 02             	shl    $0x2,%eax
 8048746:	01 d0                	add    %edx,%eax
 8048748:	c1 e0 03             	shl    $0x3,%eax
 804874b:	83 c0 64             	add    $0x64,%eax
 804874e:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8048751:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048754:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048758:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804875b:	89 04 24             	mov    %eax,(%esp)
 804875e:	e8 80 01 00 00       	call   80488e3 <fb_black_point>
 8048763:	a1 60 c0 04 08       	mov    0x804c060,%eax
 8048768:	89 c2                	mov    %eax,%edx
 804876a:	83 c0 01             	add    $0x1,%eax
 804876d:	a3 60 c0 04 08       	mov    %eax,0x804c060
 8048772:	c7 44 24 0c ff ff ff 	movl   $0xffffff,0xc(%esp)
 8048779:	00 
 804877a:	8b 45 f0             	mov    -0x10(%ebp),%eax
 804877d:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048781:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048784:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048788:	89 14 24             	mov    %edx,(%esp)
 804878b:	e8 d0 02 00 00       	call   8048a60 <fb_num>
 8048790:	e8 26 0d 00 00       	call   80494bb <get_player_win_table_max>
 8048795:	e8 6d 10 00 00       	call   8049807 <get_computer_win_table_max>
 804879a:	c9                   	leave  
 804879b:	c3                   	ret    

0804879c <fb_circle>:
 804879c:	55                   	push   %ebp
 804879d:	89 e5                	mov    %esp,%ebp
 804879f:	83 ec 68             	sub    $0x68,%esp
 80487a2:	d9 ee                	fldz   
 80487a4:	dd 5d d0             	fstpl  -0x30(%ebp)
 80487a7:	e9 8f 00 00 00       	jmp    804883b <fb_circle+0x9f>
 80487ac:	db 45 10             	fildl  0x10(%ebp)
 80487af:	dd 5d b0             	fstpl  -0x50(%ebp)
 80487b2:	dd 45 d0             	fldl   -0x30(%ebp)
 80487b5:	dd 1c 24             	fstpl  (%esp)
 80487b8:	e8 3f fd ff ff       	call   80484fc <cos@plt>
 80487bd:	dc 4d b0             	fmull  -0x50(%ebp)
 80487c0:	dd 5d e0             	fstpl  -0x20(%ebp)
 80487c3:	db 45 10             	fildl  0x10(%ebp)
 80487c6:	dd 5d b8             	fstpl  -0x48(%ebp)
 80487c9:	dd 45 d0             	fldl   -0x30(%ebp)
 80487cc:	dd 1c 24             	fstpl  (%esp)
 80487cf:	e8 58 fd ff ff       	call   804852c <sin@plt>
 80487d4:	dc 4d b8             	fmull  -0x48(%ebp)
 80487d7:	dd 5d d8             	fstpl  -0x28(%ebp)
 80487da:	dd 45 e0             	fldl   -0x20(%ebp)
 80487dd:	d9 7d c6             	fnstcw -0x3a(%ebp)
 80487e0:	0f b7 45 c6          	movzwl -0x3a(%ebp),%eax
 80487e4:	b4 0c                	mov    $0xc,%ah
 80487e6:	66 89 45 c4          	mov    %ax,-0x3c(%ebp)
 80487ea:	d9 6d c4             	fldcw  -0x3c(%ebp)
 80487ed:	db 5d c0             	fistpl -0x40(%ebp)
 80487f0:	d9 6d c6             	fldcw  -0x3a(%ebp)
 80487f3:	8b 45 c0             	mov    -0x40(%ebp),%eax
 80487f6:	03 45 08             	add    0x8(%ebp),%eax
 80487f9:	89 45 f0             	mov    %eax,-0x10(%ebp)
 80487fc:	dd 45 d8             	fldl   -0x28(%ebp)
 80487ff:	d9 6d c4             	fldcw  -0x3c(%ebp)
 8048802:	db 5d c0             	fistpl -0x40(%ebp)
 8048805:	d9 6d c6             	fldcw  -0x3a(%ebp)
 8048808:	8b 45 c0             	mov    -0x40(%ebp),%eax
 804880b:	03 45 0c             	add    0xc(%ebp),%eax
 804880e:	89 45 ec             	mov    %eax,-0x14(%ebp)
 8048811:	8b 15 e8 d6 04 08    	mov    0x804d6e8,%edx
 8048817:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 804881c:	0f af 45 ec          	imul   -0x14(%ebp),%eax
 8048820:	03 45 f0             	add    -0x10(%ebp),%eax
 8048823:	c1 e0 02             	shl    $0x2,%eax
 8048826:	01 c2                	add    %eax,%edx
 8048828:	8b 45 14             	mov    0x14(%ebp),%eax
 804882b:	89 02                	mov    %eax,(%edx)
 804882d:	dd 45 d0             	fldl   -0x30(%ebp)
 8048830:	dd 05 60 a4 04 08    	fldl   0x804a460
 8048836:	de c1                	faddp  %st,%st(1)
 8048838:	dd 5d d0             	fstpl  -0x30(%ebp)
 804883b:	dd 45 d0             	fldl   -0x30(%ebp)
 804883e:	dd 05 68 a4 04 08    	fldl   0x804a468
 8048844:	da e9                	fucompp 
 8048846:	df e0                	fnstsw %ax
 8048848:	f6 c4 05             	test   $0x5,%ah
 804884b:	0f 94 c0             	sete   %al
 804884e:	84 c0                	test   %al,%al
 8048850:	0f 85 56 ff ff ff    	jne    80487ac <fb_circle+0x10>
 8048856:	c9                   	leave  
 8048857:	c3                   	ret    

08048858 <fb_small_black_point>:
 8048858:	55                   	push   %ebp
 8048859:	89 e5                	mov    %esp,%ebp
 804885b:	83 ec 28             	sub    $0x28,%esp
 804885e:	c7 45 f4 04 00 00 00 	movl   $0x4,-0xc(%ebp)
 8048865:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 804886c:	eb 24                	jmp    8048892 <fb_small_black_point+0x3a>
 804886e:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048871:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048875:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048878:	89 44 24 08          	mov    %eax,0x8(%esp)
 804887c:	8b 45 0c             	mov    0xc(%ebp),%eax
 804887f:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048883:	8b 45 08             	mov    0x8(%ebp),%eax
 8048886:	89 04 24             	mov    %eax,(%esp)
 8048889:	e8 0e ff ff ff       	call   804879c <fb_circle>
 804888e:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 8048892:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8048896:	79 d6                	jns    804886e <fb_small_black_point+0x16>
 8048898:	c9                   	leave  
 8048899:	c3                   	ret    

0804889a <fb_white_point>:
 804889a:	55                   	push   %ebp
 804889b:	89 e5                	mov    %esp,%ebp
 804889d:	83 ec 28             	sub    $0x28,%esp
 80488a0:	c7 45 f4 12 00 00 00 	movl   $0x12,-0xc(%ebp)
 80488a7:	c7 45 f0 be be be 00 	movl   $0xbebebe,-0x10(%ebp)
 80488ae:	eb 2b                	jmp    80488db <fb_white_point+0x41>
 80488b0:	81 45 f0 03 03 03 00 	addl   $0x30303,-0x10(%ebp)
 80488b7:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80488ba:	89 44 24 0c          	mov    %eax,0xc(%esp)
 80488be:	8b 45 f4             	mov    -0xc(%ebp),%eax
 80488c1:	89 44 24 08          	mov    %eax,0x8(%esp)
 80488c5:	8b 45 0c             	mov    0xc(%ebp),%eax
 80488c8:	89 44 24 04          	mov    %eax,0x4(%esp)
 80488cc:	8b 45 08             	mov    0x8(%ebp),%eax
 80488cf:	89 04 24             	mov    %eax,(%esp)
 80488d2:	e8 c5 fe ff ff       	call   804879c <fb_circle>
 80488d7:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 80488db:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 80488df:	79 cf                	jns    80488b0 <fb_white_point+0x16>
 80488e1:	c9                   	leave  
 80488e2:	c3                   	ret    

080488e3 <fb_black_point>:
 80488e3:	55                   	push   %ebp
 80488e4:	89 e5                	mov    %esp,%ebp
 80488e6:	83 ec 28             	sub    $0x28,%esp
 80488e9:	c7 45 f4 12 00 00 00 	movl   $0x12,-0xc(%ebp)
 80488f0:	c7 45 f0 15 15 15 00 	movl   $0x151515,-0x10(%ebp)
 80488f7:	eb 2b                	jmp    8048924 <fb_black_point+0x41>
 80488f9:	81 45 f0 04 04 04 00 	addl   $0x40404,-0x10(%ebp)
 8048900:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048903:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048907:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804890a:	89 44 24 08          	mov    %eax,0x8(%esp)
 804890e:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048911:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048915:	8b 45 08             	mov    0x8(%ebp),%eax
 8048918:	89 04 24             	mov    %eax,(%esp)
 804891b:	e8 7c fe ff ff       	call   804879c <fb_circle>
 8048920:	83 6d f4 01          	subl   $0x1,-0xc(%ebp)
 8048924:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8048928:	79 cf                	jns    80488f9 <fb_black_point+0x16>
 804892a:	c9                   	leave  
 804892b:	c3                   	ret    

0804892c <fb_grid>:
 804892c:	55                   	push   %ebp
 804892d:	89 e5                	mov    %esp,%ebp
 804892f:	83 ec 20             	sub    $0x20,%esp
 8048932:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 8048939:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8048940:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048943:	89 45 ec             	mov    %eax,-0x14(%ebp)
 8048946:	c7 45 f4 30 02 00 00 	movl   $0x230,-0xc(%ebp)
 804894d:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8048954:	eb 3c                	jmp    8048992 <fb_grid+0x66>
 8048956:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 804895d:	eb 23                	jmp    8048982 <fb_grid+0x56>
 804895f:	8b 15 e8 d6 04 08    	mov    0x804d6e8,%edx
 8048965:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 804896a:	0f af 45 0c          	imul   0xc(%ebp),%eax
 804896e:	03 45 08             	add    0x8(%ebp),%eax
 8048971:	03 45 f8             	add    -0x8(%ebp),%eax
 8048974:	c1 e0 02             	shl    $0x2,%eax
 8048977:	01 c2                	add    %eax,%edx
 8048979:	8b 45 10             	mov    0x10(%ebp),%eax
 804897c:	89 02                	mov    %eax,(%edx)
 804897e:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
 8048982:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8048985:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 8048988:	7c d5                	jl     804895f <fb_grid+0x33>
 804898a:	83 45 0c 28          	addl   $0x28,0xc(%ebp)
 804898e:	83 45 f0 28          	addl   $0x28,-0x10(%ebp)
 8048992:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048995:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 8048998:	7e bc                	jle    8048956 <fb_grid+0x2a>
 804899a:	8b 45 ec             	mov    -0x14(%ebp),%eax
 804899d:	89 45 0c             	mov    %eax,0xc(%ebp)
 80489a0:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 80489a7:	eb 40                	jmp    80489e9 <fb_grid+0xbd>
 80489a9:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 80489b0:	eb 27                	jmp    80489d9 <fb_grid+0xad>
 80489b2:	8b 15 e8 d6 04 08    	mov    0x804d6e8,%edx
 80489b8:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80489bb:	8b 4d 0c             	mov    0xc(%ebp),%ecx
 80489be:	01 c1                	add    %eax,%ecx
 80489c0:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 80489c5:	0f af c1             	imul   %ecx,%eax
 80489c8:	03 45 08             	add    0x8(%ebp),%eax
 80489cb:	c1 e0 02             	shl    $0x2,%eax
 80489ce:	01 c2                	add    %eax,%edx
 80489d0:	8b 45 10             	mov    0x10(%ebp),%eax
 80489d3:	89 02                	mov    %eax,(%edx)
 80489d5:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
 80489d9:	8b 45 f8             	mov    -0x8(%ebp),%eax
 80489dc:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 80489df:	7c d1                	jl     80489b2 <fb_grid+0x86>
 80489e1:	83 45 08 28          	addl   $0x28,0x8(%ebp)
 80489e5:	83 45 f0 28          	addl   $0x28,-0x10(%ebp)
 80489e9:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80489ec:	3b 45 f4             	cmp    -0xc(%ebp),%eax
 80489ef:	7e b8                	jle    80489a9 <fb_grid+0x7d>
 80489f1:	c9                   	leave  
 80489f2:	c3                   	ret    

080489f3 <fb_bg>:
 80489f3:	55                   	push   %ebp
 80489f4:	89 e5                	mov    %esp,%ebp
 80489f6:	83 ec 10             	sub    $0x10,%esp
 80489f9:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8048a00:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8048a07:	c7 45 f8 6c 02 00 00 	movl   $0x26c,-0x8(%ebp)
 8048a0e:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8048a15:	eb 3c                	jmp    8048a53 <fb_bg+0x60>
 8048a17:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8048a1e:	eb 23                	jmp    8048a43 <fb_bg+0x50>
 8048a20:	8b 15 e8 d6 04 08    	mov    0x804d6e8,%edx
 8048a26:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 8048a2b:	0f af 45 0c          	imul   0xc(%ebp),%eax
 8048a2f:	03 45 08             	add    0x8(%ebp),%eax
 8048a32:	03 45 f0             	add    -0x10(%ebp),%eax
 8048a35:	c1 e0 02             	shl    $0x2,%eax
 8048a38:	01 c2                	add    %eax,%edx
 8048a3a:	8b 45 10             	mov    0x10(%ebp),%eax
 8048a3d:	89 02                	mov    %eax,(%edx)
 8048a3f:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 8048a43:	8b 45 f0             	mov    -0x10(%ebp),%eax
 8048a46:	3b 45 f8             	cmp    -0x8(%ebp),%eax
 8048a49:	7c d5                	jl     8048a20 <fb_bg+0x2d>
 8048a4b:	83 45 0c 01          	addl   $0x1,0xc(%ebp)
 8048a4f:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8048a53:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048a56:	3b 45 f8             	cmp    -0x8(%ebp),%eax
 8048a59:	7c bc                	jl     8048a17 <fb_bg+0x24>
 8048a5b:	c9                   	leave  
 8048a5c:	c3                   	ret    
 8048a5d:	90                   	nop
 8048a5e:	90                   	nop
 8048a5f:	90                   	nop

08048a60 <fb_num>:
 8048a60:	55                   	push   %ebp
 8048a61:	89 e5                	mov    %esp,%ebp
 8048a63:	53                   	push   %ebx
 8048a64:	83 ec 30             	sub    $0x30,%esp
 8048a67:	8b 45 08             	mov    0x8(%ebp),%eax
 8048a6a:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 8048a6d:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 8048a74:	8b 45 10             	mov    0x10(%ebp),%eax
 8048a77:	89 45 e0             	mov    %eax,-0x20(%ebp)
 8048a7a:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 8048a7e:	78 1d                	js     8048a9d <fb_num+0x3d>
 8048a80:	83 7d 08 09          	cmpl   $0x9,0x8(%ebp)
 8048a84:	7f 17                	jg     8048a9d <fb_num+0x3d>
 8048a86:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%ebp)
 8048a8d:	c7 45 dc 03 00 00 00 	movl   $0x3,-0x24(%ebp)
 8048a94:	c7 45 d8 07 00 00 00 	movl   $0x7,-0x28(%ebp)
 8048a9b:	eb 54                	jmp    8048af1 <fb_num+0x91>
 8048a9d:	83 7d 08 09          	cmpl   $0x9,0x8(%ebp)
 8048aa1:	7e 1d                	jle    8048ac0 <fb_num+0x60>
 8048aa3:	83 7d 08 63          	cmpl   $0x63,0x8(%ebp)
 8048aa7:	7f 17                	jg     8048ac0 <fb_num+0x60>
 8048aa9:	c7 45 d4 02 00 00 00 	movl   $0x2,-0x2c(%ebp)
 8048ab0:	c7 45 dc 01 00 00 00 	movl   $0x1,-0x24(%ebp)
 8048ab7:	c7 45 d8 07 00 00 00 	movl   $0x7,-0x28(%ebp)
 8048abe:	eb 31                	jmp    8048af1 <fb_num+0x91>
 8048ac0:	83 7d 08 63          	cmpl   $0x63,0x8(%ebp)
 8048ac4:	0f 8e 27 01 00 00    	jle    8048bf1 <fb_num+0x191>
 8048aca:	81 7d 08 e7 03 00 00 	cmpl   $0x3e7,0x8(%ebp)
 8048ad1:	0f 8f 1a 01 00 00    	jg     8048bf1 <fb_num+0x191>
 8048ad7:	c7 45 d4 03 00 00 00 	movl   $0x3,-0x2c(%ebp)
 8048ade:	c7 45 dc fc ff ff ff 	movl   $0xfffffffc,-0x24(%ebp)
 8048ae5:	c7 45 d8 07 00 00 00 	movl   $0x7,-0x28(%ebp)
 8048aec:	e9 00 01 00 00       	jmp    8048bf1 <fb_num+0x191>
 8048af1:	e9 fb 00 00 00       	jmp    8048bf1 <fb_num+0x191>
 8048af6:	8b 45 e0             	mov    -0x20(%ebp),%eax
 8048af9:	89 45 10             	mov    %eax,0x10(%ebp)
 8048afc:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8048b03:	e9 be 00 00 00       	jmp    8048bc6 <fb_num+0x166>
 8048b08:	c7 45 f8 07 00 00 00 	movl   $0x7,-0x8(%ebp)
 8048b0f:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8048b16:	e9 99 00 00 00       	jmp    8048bb4 <fb_num+0x154>
 8048b1b:	8b 4d e4             	mov    -0x1c(%ebp),%ecx
 8048b1e:	ba 67 66 66 66       	mov    $0x66666667,%edx
 8048b23:	89 c8                	mov    %ecx,%eax
 8048b25:	f7 ea                	imul   %edx
 8048b27:	c1 fa 02             	sar    $0x2,%edx
 8048b2a:	89 c8                	mov    %ecx,%eax
 8048b2c:	c1 f8 1f             	sar    $0x1f,%eax
 8048b2f:	29 c2                	sub    %eax,%edx
 8048b31:	89 d0                	mov    %edx,%eax
 8048b33:	c1 e0 02             	shl    $0x2,%eax
 8048b36:	01 d0                	add    %edx,%eax
 8048b38:	01 c0                	add    %eax,%eax
 8048b3a:	89 ca                	mov    %ecx,%edx
 8048b3c:	29 c2                	sub    %eax,%edx
 8048b3e:	89 d0                	mov    %edx,%eax
 8048b40:	89 45 e8             	mov    %eax,-0x18(%ebp)
 8048b43:	8b 55 e8             	mov    -0x18(%ebp),%edx
 8048b46:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048b49:	c1 e2 04             	shl    $0x4,%edx
 8048b4c:	8d 04 02             	lea    (%edx,%eax,1),%eax
 8048b4f:	05 c0 c3 04 08       	add    $0x804c3c0,%eax
 8048b54:	0f b6 00             	movzbl (%eax),%eax
 8048b57:	0f b6 d0             	movzbl %al,%edx
 8048b5a:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8048b5d:	89 d3                	mov    %edx,%ebx
 8048b5f:	89 c1                	mov    %eax,%ecx
 8048b61:	d3 fb                	sar    %cl,%ebx
 8048b63:	89 d8                	mov    %ebx,%eax
 8048b65:	83 e0 01             	and    $0x1,%eax
 8048b68:	84 c0                	test   %al,%al
 8048b6a:	74 40                	je     8048bac <fb_num+0x14c>
 8048b6c:	a1 e8 d6 04 08       	mov    0x804d6e8,%eax
 8048b71:	8b 55 d8             	mov    -0x28(%ebp),%edx
 8048b74:	8b 4d 10             	mov    0x10(%ebp),%ecx
 8048b77:	29 d1                	sub    %edx,%ecx
 8048b79:	8b 15 e4 d6 04 08    	mov    0x804d6e4,%edx
 8048b7f:	0f af d1             	imul   %ecx,%edx
 8048b82:	89 d1                	mov    %edx,%ecx
 8048b84:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048b87:	01 d1                	add    %edx,%ecx
 8048b89:	8b 55 f0             	mov    -0x10(%ebp),%edx
 8048b8c:	01 d1                	add    %edx,%ecx
 8048b8e:	8b 55 ec             	mov    -0x14(%ebp),%edx
 8048b91:	c1 e2 03             	shl    $0x3,%edx
 8048b94:	f7 da                	neg    %edx
 8048b96:	01 d1                	add    %edx,%ecx
 8048b98:	8b 55 dc             	mov    -0x24(%ebp),%edx
 8048b9b:	89 cb                	mov    %ecx,%ebx
 8048b9d:	29 d3                	sub    %edx,%ebx
 8048b9f:	89 da                	mov    %ebx,%edx
 8048ba1:	c1 e2 02             	shl    $0x2,%edx
 8048ba4:	8d 14 10             	lea    (%eax,%edx,1),%edx
 8048ba7:	8b 45 14             	mov    0x14(%ebp),%eax
 8048baa:	89 02                	mov    %eax,(%edx)
 8048bac:	83 6d f8 01          	subl   $0x1,-0x8(%ebp)
 8048bb0:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 8048bb4:	83 7d f8 00          	cmpl   $0x0,-0x8(%ebp)
 8048bb8:	0f 89 5d ff ff ff    	jns    8048b1b <fb_num+0xbb>
 8048bbe:	83 45 10 01          	addl   $0x1,0x10(%ebp)
 8048bc2:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8048bc6:	83 7d f4 0f          	cmpl   $0xf,-0xc(%ebp)
 8048bca:	0f 8e 38 ff ff ff    	jle    8048b08 <fb_num+0xa8>
 8048bd0:	8b 4d e4             	mov    -0x1c(%ebp),%ecx
 8048bd3:	ba 67 66 66 66       	mov    $0x66666667,%edx
 8048bd8:	89 c8                	mov    %ecx,%eax
 8048bda:	f7 ea                	imul   %edx
 8048bdc:	c1 fa 02             	sar    $0x2,%edx
 8048bdf:	89 c8                	mov    %ecx,%eax
 8048be1:	c1 f8 1f             	sar    $0x1f,%eax
 8048be4:	89 d1                	mov    %edx,%ecx
 8048be6:	29 c1                	sub    %eax,%ecx
 8048be8:	89 c8                	mov    %ecx,%eax
 8048bea:	89 45 e4             	mov    %eax,-0x1c(%ebp)
 8048bed:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 8048bf1:	83 7d e4 00          	cmpl   $0x0,-0x1c(%ebp)
 8048bf5:	0f 85 fb fe ff ff    	jne    8048af6 <fb_num+0x96>
 8048bfb:	83 c4 30             	add    $0x30,%esp
 8048bfe:	5b                   	pop    %ebx
 8048bff:	5d                   	pop    %ebp
 8048c00:	c3                   	ret    
 8048c01:	90                   	nop
 8048c02:	90                   	nop
 8048c03:	90                   	nop

08048c04 <reset>:
 8048c04:	55                   	push   %ebp
 8048c05:	89 e5                	mov    %esp,%ebp
 8048c07:	c7 05 94 d6 04 08 00 	movl   $0x0,0x804d694
 8048c0e:	00 00 00 
 8048c11:	eb 53                	jmp    8048c66 <reset+0x62>
 8048c13:	c7 05 98 d6 04 08 00 	movl   $0x0,0x804d698
 8048c1a:	00 00 00 
 8048c1d:	eb 30                	jmp    8048c4f <reset+0x4b>
 8048c1f:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8048c24:	c1 e0 02             	shl    $0x2,%eax
 8048c27:	89 c2                	mov    %eax,%edx
 8048c29:	c1 e2 04             	shl    $0x4,%edx
 8048c2c:	89 d1                	mov    %edx,%ecx
 8048c2e:	29 c1                	sub    %eax,%ecx
 8048c30:	89 c8                	mov    %ecx,%eax
 8048c32:	03 45 08             	add    0x8(%ebp),%eax
 8048c35:	8b 15 94 d6 04 08    	mov    0x804d694,%edx
 8048c3b:	c7 04 90 00 00 00 00 	movl   $0x0,(%eax,%edx,4)
 8048c42:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8048c47:	83 c0 01             	add    $0x1,%eax
 8048c4a:	a3 98 d6 04 08       	mov    %eax,0x804d698
 8048c4f:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8048c54:	83 f8 0e             	cmp    $0xe,%eax
 8048c57:	7e c6                	jle    8048c1f <reset+0x1b>
 8048c59:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8048c5e:	83 c0 01             	add    $0x1,%eax
 8048c61:	a3 94 d6 04 08       	mov    %eax,0x804d694
 8048c66:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8048c6b:	83 f8 0e             	cmp    $0xe,%eax
 8048c6e:	7e a3                	jle    8048c13 <reset+0xf>
 8048c70:	5d                   	pop    %ebp
 8048c71:	c3                   	ret    

08048c72 <win>:
 8048c72:	55                   	push   %ebp
 8048c73:	89 e5                	mov    %esp,%ebp
 8048c75:	83 ec 18             	sub    $0x18,%esp
 8048c78:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 8048c7d:	83 f8 05             	cmp    $0x5,%eax
 8048c80:	75 17                	jne    8048c99 <win+0x27>
 8048c82:	8b 45 08             	mov    0x8(%ebp),%eax
 8048c85:	89 04 24             	mov    %eax,(%esp)
 8048c88:	e8 8f f8 ff ff       	call   804851c <puts@plt>
 8048c8d:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8048c94:	e8 a3 f8 ff ff       	call   804853c <exit@plt>
 8048c99:	c9                   	leave  
 8048c9a:	c3                   	ret    

08048c9b <left>:
 8048c9b:	55                   	push   %ebp
 8048c9c:	89 e5                	mov    %esp,%ebp
 8048c9e:	83 ec 18             	sub    $0x18,%esp
 8048ca1:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048ca4:	83 e8 01             	sub    $0x1,%eax
 8048ca7:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048cac:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048cb3:	00 00 00 
 8048cb6:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 8048cbd:	00 00 00 
 8048cc0:	e9 8d 00 00 00       	jmp    8048d52 <left+0xb7>
 8048cc5:	8b 15 9c d6 04 08    	mov    0x804d69c,%edx
 8048ccb:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8048cce:	89 d0                	mov    %edx,%eax
 8048cd0:	c1 e0 04             	shl    $0x4,%eax
 8048cd3:	29 d0                	sub    %edx,%eax
 8048cd5:	01 c8                	add    %ecx,%eax
 8048cd7:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048cde:	3b 45 10             	cmp    0x10(%ebp),%eax
 8048ce1:	75 0f                	jne    8048cf2 <left+0x57>
 8048ce3:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 8048ce8:	83 c0 01             	add    $0x1,%eax
 8048ceb:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 8048cf0:	eb 53                	jmp    8048d45 <left+0xaa>
 8048cf2:	8b 15 9c d6 04 08    	mov    0x804d69c,%edx
 8048cf8:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8048cfb:	89 d0                	mov    %edx,%eax
 8048cfd:	c1 e0 04             	shl    $0x4,%eax
 8048d00:	29 d0                	sub    %edx,%eax
 8048d02:	01 c8                	add    %ecx,%eax
 8048d04:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048d0b:	3b 45 14             	cmp    0x14(%ebp),%eax
 8048d0e:	75 0c                	jne    8048d1c <left+0x81>
 8048d10:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048d17:	00 00 00 
 8048d1a:	eb 43                	jmp    8048d5f <left+0xc4>
 8048d1c:	8b 15 9c d6 04 08    	mov    0x804d69c,%edx
 8048d22:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8048d25:	89 d0                	mov    %edx,%eax
 8048d27:	c1 e0 04             	shl    $0x4,%eax
 8048d2a:	29 d0                	sub    %edx,%eax
 8048d2c:	01 c8                	add    %ecx,%eax
 8048d2e:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048d35:	85 c0                	test   %eax,%eax
 8048d37:	75 0c                	jne    8048d45 <left+0xaa>
 8048d39:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 8048d40:	00 00 00 
 8048d43:	eb 1a                	jmp    8048d5f <left+0xc4>
 8048d45:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8048d4a:	83 e8 01             	sub    $0x1,%eax
 8048d4d:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048d52:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8048d57:	85 c0                	test   %eax,%eax
 8048d59:	0f 89 66 ff ff ff    	jns    8048cc5 <left+0x2a>
 8048d5f:	8b 45 18             	mov    0x18(%ebp),%eax
 8048d62:	89 04 24             	mov    %eax,(%esp)
 8048d65:	e8 08 ff ff ff       	call   8048c72 <win>
 8048d6a:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 8048d6f:	89 c2                	mov    %eax,%edx
 8048d71:	89 d0                	mov    %edx,%eax
 8048d73:	c1 e0 02             	shl    $0x2,%eax
 8048d76:	01 d0                	add    %edx,%eax
 8048d78:	c1 e0 02             	shl    $0x2,%eax
 8048d7b:	03 45 1c             	add    0x1c(%ebp),%eax
 8048d7e:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 8048d84:	8b 04 90             	mov    (%eax,%edx,4),%eax
 8048d87:	a3 ac d6 04 08       	mov    %eax,0x804d6ac
 8048d8c:	c9                   	leave  
 8048d8d:	c3                   	ret    

08048d8e <right>:
 8048d8e:	55                   	push   %ebp
 8048d8f:	89 e5                	mov    %esp,%ebp
 8048d91:	83 ec 18             	sub    $0x18,%esp
 8048d94:	8b 45 0c             	mov    0xc(%ebp),%eax
 8048d97:	83 c0 01             	add    $0x1,%eax
 8048d9a:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048d9f:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048da6:	00 00 00 
 8048da9:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 8048db0:	00 00 00 
 8048db3:	e9 8d 00 00 00       	jmp    8048e45 <right+0xb7>
 8048db8:	8b 15 9c d6 04 08    	mov    0x804d69c,%edx
 8048dbe:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8048dc1:	89 d0                	mov    %edx,%eax
 8048dc3:	c1 e0 04             	shl    $0x4,%eax
 8048dc6:	29 d0                	sub    %edx,%eax
 8048dc8:	01 c8                	add    %ecx,%eax
 8048dca:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048dd1:	3b 45 10             	cmp    0x10(%ebp),%eax
 8048dd4:	75 0f                	jne    8048de5 <right+0x57>
 8048dd6:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 8048ddb:	83 c0 01             	add    $0x1,%eax
 8048dde:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 8048de3:	eb 53                	jmp    8048e38 <right+0xaa>
 8048de5:	8b 15 9c d6 04 08    	mov    0x804d69c,%edx
 8048deb:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8048dee:	89 d0                	mov    %edx,%eax
 8048df0:	c1 e0 04             	shl    $0x4,%eax
 8048df3:	29 d0                	sub    %edx,%eax
 8048df5:	01 c8                	add    %ecx,%eax
 8048df7:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048dfe:	3b 45 14             	cmp    0x14(%ebp),%eax
 8048e01:	75 0c                	jne    8048e0f <right+0x81>
 8048e03:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048e0a:	00 00 00 
 8048e0d:	eb 44                	jmp    8048e53 <right+0xc5>
 8048e0f:	8b 15 9c d6 04 08    	mov    0x804d69c,%edx
 8048e15:	8b 4d 08             	mov    0x8(%ebp),%ecx
 8048e18:	89 d0                	mov    %edx,%eax
 8048e1a:	c1 e0 04             	shl    $0x4,%eax
 8048e1d:	29 d0                	sub    %edx,%eax
 8048e1f:	01 c8                	add    %ecx,%eax
 8048e21:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048e28:	85 c0                	test   %eax,%eax
 8048e2a:	75 0c                	jne    8048e38 <right+0xaa>
 8048e2c:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 8048e33:	00 00 00 
 8048e36:	eb 1b                	jmp    8048e53 <right+0xc5>
 8048e38:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8048e3d:	83 c0 01             	add    $0x1,%eax
 8048e40:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048e45:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8048e4a:	83 f8 0e             	cmp    $0xe,%eax
 8048e4d:	0f 8e 65 ff ff ff    	jle    8048db8 <right+0x2a>
 8048e53:	8b 45 18             	mov    0x18(%ebp),%eax
 8048e56:	89 04 24             	mov    %eax,(%esp)
 8048e59:	e8 14 fe ff ff       	call   8048c72 <win>
 8048e5e:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 8048e63:	89 c2                	mov    %eax,%edx
 8048e65:	89 d0                	mov    %edx,%eax
 8048e67:	c1 e0 02             	shl    $0x2,%eax
 8048e6a:	01 d0                	add    %edx,%eax
 8048e6c:	c1 e0 02             	shl    $0x2,%eax
 8048e6f:	03 45 1c             	add    0x1c(%ebp),%eax
 8048e72:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 8048e78:	8b 04 90             	mov    (%eax,%edx,4),%eax
 8048e7b:	a3 b0 d6 04 08       	mov    %eax,0x804d6b0
 8048e80:	c9                   	leave  
 8048e81:	c3                   	ret    

08048e82 <up>:
 8048e82:	55                   	push   %ebp
 8048e83:	89 e5                	mov    %esp,%ebp
 8048e85:	83 ec 18             	sub    $0x18,%esp
 8048e88:	8b 45 08             	mov    0x8(%ebp),%eax
 8048e8b:	83 e8 01             	sub    $0x1,%eax
 8048e8e:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048e93:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048e9a:	00 00 00 
 8048e9d:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 8048ea4:	00 00 00 
 8048ea7:	e9 8d 00 00 00       	jmp    8048f39 <up+0xb7>
 8048eac:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048eaf:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8048eb5:	89 d0                	mov    %edx,%eax
 8048eb7:	c1 e0 04             	shl    $0x4,%eax
 8048eba:	29 d0                	sub    %edx,%eax
 8048ebc:	01 c8                	add    %ecx,%eax
 8048ebe:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048ec5:	3b 45 10             	cmp    0x10(%ebp),%eax
 8048ec8:	75 0f                	jne    8048ed9 <up+0x57>
 8048eca:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 8048ecf:	83 c0 01             	add    $0x1,%eax
 8048ed2:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 8048ed7:	eb 53                	jmp    8048f2c <up+0xaa>
 8048ed9:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048edc:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8048ee2:	89 d0                	mov    %edx,%eax
 8048ee4:	c1 e0 04             	shl    $0x4,%eax
 8048ee7:	29 d0                	sub    %edx,%eax
 8048ee9:	01 c8                	add    %ecx,%eax
 8048eeb:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048ef2:	3b 45 14             	cmp    0x14(%ebp),%eax
 8048ef5:	75 0c                	jne    8048f03 <up+0x81>
 8048ef7:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048efe:	00 00 00 
 8048f01:	eb 43                	jmp    8048f46 <up+0xc4>
 8048f03:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048f06:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8048f0c:	89 d0                	mov    %edx,%eax
 8048f0e:	c1 e0 04             	shl    $0x4,%eax
 8048f11:	29 d0                	sub    %edx,%eax
 8048f13:	01 c8                	add    %ecx,%eax
 8048f15:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048f1c:	85 c0                	test   %eax,%eax
 8048f1e:	75 0c                	jne    8048f2c <up+0xaa>
 8048f20:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 8048f27:	00 00 00 
 8048f2a:	eb 1a                	jmp    8048f46 <up+0xc4>
 8048f2c:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8048f31:	83 e8 01             	sub    $0x1,%eax
 8048f34:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048f39:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8048f3e:	85 c0                	test   %eax,%eax
 8048f40:	0f 89 66 ff ff ff    	jns    8048eac <up+0x2a>
 8048f46:	8b 45 18             	mov    0x18(%ebp),%eax
 8048f49:	89 04 24             	mov    %eax,(%esp)
 8048f4c:	e8 21 fd ff ff       	call   8048c72 <win>
 8048f51:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 8048f56:	89 c2                	mov    %eax,%edx
 8048f58:	89 d0                	mov    %edx,%eax
 8048f5a:	c1 e0 02             	shl    $0x2,%eax
 8048f5d:	01 d0                	add    %edx,%eax
 8048f5f:	c1 e0 02             	shl    $0x2,%eax
 8048f62:	03 45 1c             	add    0x1c(%ebp),%eax
 8048f65:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 8048f6b:	8b 04 90             	mov    (%eax,%edx,4),%eax
 8048f6e:	a3 b4 d6 04 08       	mov    %eax,0x804d6b4
 8048f73:	c9                   	leave  
 8048f74:	c3                   	ret    

08048f75 <down>:
 8048f75:	55                   	push   %ebp
 8048f76:	89 e5                	mov    %esp,%ebp
 8048f78:	83 ec 18             	sub    $0x18,%esp
 8048f7b:	8b 45 08             	mov    0x8(%ebp),%eax
 8048f7e:	83 c0 01             	add    $0x1,%eax
 8048f81:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8048f86:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048f8d:	00 00 00 
 8048f90:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 8048f97:	00 00 00 
 8048f9a:	e9 8d 00 00 00       	jmp    804902c <down+0xb7>
 8048f9f:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048fa2:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8048fa8:	89 d0                	mov    %edx,%eax
 8048faa:	c1 e0 04             	shl    $0x4,%eax
 8048fad:	29 d0                	sub    %edx,%eax
 8048faf:	01 c8                	add    %ecx,%eax
 8048fb1:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048fb8:	3b 45 10             	cmp    0x10(%ebp),%eax
 8048fbb:	75 0f                	jne    8048fcc <down+0x57>
 8048fbd:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 8048fc2:	83 c0 01             	add    $0x1,%eax
 8048fc5:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 8048fca:	eb 53                	jmp    804901f <down+0xaa>
 8048fcc:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048fcf:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8048fd5:	89 d0                	mov    %edx,%eax
 8048fd7:	c1 e0 04             	shl    $0x4,%eax
 8048fda:	29 d0                	sub    %edx,%eax
 8048fdc:	01 c8                	add    %ecx,%eax
 8048fde:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8048fe5:	3b 45 14             	cmp    0x14(%ebp),%eax
 8048fe8:	75 0c                	jne    8048ff6 <down+0x81>
 8048fea:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8048ff1:	00 00 00 
 8048ff4:	eb 44                	jmp    804903a <down+0xc5>
 8048ff6:	8b 55 0c             	mov    0xc(%ebp),%edx
 8048ff9:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8048fff:	89 d0                	mov    %edx,%eax
 8049001:	c1 e0 04             	shl    $0x4,%eax
 8049004:	29 d0                	sub    %edx,%eax
 8049006:	01 c8                	add    %ecx,%eax
 8049008:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 804900f:	85 c0                	test   %eax,%eax
 8049011:	75 0c                	jne    804901f <down+0xaa>
 8049013:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 804901a:	00 00 00 
 804901d:	eb 1b                	jmp    804903a <down+0xc5>
 804901f:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8049024:	83 c0 01             	add    $0x1,%eax
 8049027:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 804902c:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8049031:	83 f8 0e             	cmp    $0xe,%eax
 8049034:	0f 8e 65 ff ff ff    	jle    8048f9f <down+0x2a>
 804903a:	8b 45 18             	mov    0x18(%ebp),%eax
 804903d:	89 04 24             	mov    %eax,(%esp)
 8049040:	e8 2d fc ff ff       	call   8048c72 <win>
 8049045:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 804904a:	89 c2                	mov    %eax,%edx
 804904c:	89 d0                	mov    %edx,%eax
 804904e:	c1 e0 02             	shl    $0x2,%eax
 8049051:	01 d0                	add    %edx,%eax
 8049053:	c1 e0 02             	shl    $0x2,%eax
 8049056:	03 45 1c             	add    0x1c(%ebp),%eax
 8049059:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 804905f:	8b 04 90             	mov    (%eax,%edx,4),%eax
 8049062:	a3 b8 d6 04 08       	mov    %eax,0x804d6b8
 8049067:	c9                   	leave  
 8049068:	c3                   	ret    

08049069 <left_up>:
 8049069:	55                   	push   %ebp
 804906a:	89 e5                	mov    %esp,%ebp
 804906c:	83 ec 18             	sub    $0x18,%esp
 804906f:	8b 45 08             	mov    0x8(%ebp),%eax
 8049072:	83 e8 01             	sub    $0x1,%eax
 8049075:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 804907a:	8b 45 0c             	mov    0xc(%ebp),%eax
 804907d:	83 e8 01             	sub    $0x1,%eax
 8049080:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 8049085:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 804908c:	00 00 00 
 804908f:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 8049096:	00 00 00 
 8049099:	e9 a3 00 00 00       	jmp    8049141 <left_up+0xd8>
 804909e:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80490a4:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 80490aa:	89 d0                	mov    %edx,%eax
 80490ac:	c1 e0 04             	shl    $0x4,%eax
 80490af:	29 d0                	sub    %edx,%eax
 80490b1:	01 c8                	add    %ecx,%eax
 80490b3:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 80490ba:	3b 45 10             	cmp    0x10(%ebp),%eax
 80490bd:	75 0f                	jne    80490ce <left_up+0x65>
 80490bf:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 80490c4:	83 c0 01             	add    $0x1,%eax
 80490c7:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 80490cc:	eb 59                	jmp    8049127 <left_up+0xbe>
 80490ce:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80490d4:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 80490da:	89 d0                	mov    %edx,%eax
 80490dc:	c1 e0 04             	shl    $0x4,%eax
 80490df:	29 d0                	sub    %edx,%eax
 80490e1:	01 c8                	add    %ecx,%eax
 80490e3:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 80490ea:	3b 45 14             	cmp    0x14(%ebp),%eax
 80490ed:	75 0c                	jne    80490fb <left_up+0x92>
 80490ef:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 80490f6:	00 00 00 
 80490f9:	eb 53                	jmp    804914e <left_up+0xe5>
 80490fb:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 8049101:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8049107:	89 d0                	mov    %edx,%eax
 8049109:	c1 e0 04             	shl    $0x4,%eax
 804910c:	29 d0                	sub    %edx,%eax
 804910e:	01 c8                	add    %ecx,%eax
 8049110:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8049117:	85 c0                	test   %eax,%eax
 8049119:	75 0c                	jne    8049127 <left_up+0xbe>
 804911b:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 8049122:	00 00 00 
 8049125:	eb 27                	jmp    804914e <left_up+0xe5>
 8049127:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 804912c:	83 e8 01             	sub    $0x1,%eax
 804912f:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8049134:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 8049139:	83 e8 01             	sub    $0x1,%eax
 804913c:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 8049141:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 8049146:	85 c0                	test   %eax,%eax
 8049148:	0f 89 50 ff ff ff    	jns    804909e <left_up+0x35>
 804914e:	8b 45 18             	mov    0x18(%ebp),%eax
 8049151:	89 04 24             	mov    %eax,(%esp)
 8049154:	e8 19 fb ff ff       	call   8048c72 <win>
 8049159:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 804915e:	89 c2                	mov    %eax,%edx
 8049160:	89 d0                	mov    %edx,%eax
 8049162:	c1 e0 02             	shl    $0x2,%eax
 8049165:	01 d0                	add    %edx,%eax
 8049167:	c1 e0 02             	shl    $0x2,%eax
 804916a:	03 45 1c             	add    0x1c(%ebp),%eax
 804916d:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 8049173:	8b 04 90             	mov    (%eax,%edx,4),%eax
 8049176:	a3 bc d6 04 08       	mov    %eax,0x804d6bc
 804917b:	c9                   	leave  
 804917c:	c3                   	ret    

0804917d <right_up>:
 804917d:	55                   	push   %ebp
 804917e:	89 e5                	mov    %esp,%ebp
 8049180:	83 ec 18             	sub    $0x18,%esp
 8049183:	8b 45 08             	mov    0x8(%ebp),%eax
 8049186:	83 e8 01             	sub    $0x1,%eax
 8049189:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 804918e:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049191:	83 c0 01             	add    $0x1,%eax
 8049194:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 8049199:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 80491a0:	00 00 00 
 80491a3:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 80491aa:	00 00 00 
 80491ad:	e9 a3 00 00 00       	jmp    8049255 <right_up+0xd8>
 80491b2:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80491b8:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 80491be:	89 d0                	mov    %edx,%eax
 80491c0:	c1 e0 04             	shl    $0x4,%eax
 80491c3:	29 d0                	sub    %edx,%eax
 80491c5:	01 c8                	add    %ecx,%eax
 80491c7:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 80491ce:	3b 45 10             	cmp    0x10(%ebp),%eax
 80491d1:	75 0f                	jne    80491e2 <right_up+0x65>
 80491d3:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 80491d8:	83 c0 01             	add    $0x1,%eax
 80491db:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 80491e0:	eb 59                	jmp    804923b <right_up+0xbe>
 80491e2:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80491e8:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 80491ee:	89 d0                	mov    %edx,%eax
 80491f0:	c1 e0 04             	shl    $0x4,%eax
 80491f3:	29 d0                	sub    %edx,%eax
 80491f5:	01 c8                	add    %ecx,%eax
 80491f7:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 80491fe:	3b 45 14             	cmp    0x14(%ebp),%eax
 8049201:	75 0c                	jne    804920f <right_up+0x92>
 8049203:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 804920a:	00 00 00 
 804920d:	eb 54                	jmp    8049263 <right_up+0xe6>
 804920f:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 8049215:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 804921b:	89 d0                	mov    %edx,%eax
 804921d:	c1 e0 04             	shl    $0x4,%eax
 8049220:	29 d0                	sub    %edx,%eax
 8049222:	01 c8                	add    %ecx,%eax
 8049224:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 804922b:	85 c0                	test   %eax,%eax
 804922d:	75 0c                	jne    804923b <right_up+0xbe>
 804922f:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 8049236:	00 00 00 
 8049239:	eb 28                	jmp    8049263 <right_up+0xe6>
 804923b:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8049240:	83 e8 01             	sub    $0x1,%eax
 8049243:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8049248:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 804924d:	83 c0 01             	add    $0x1,%eax
 8049250:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 8049255:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 804925a:	83 f8 0e             	cmp    $0xe,%eax
 804925d:	0f 8e 4f ff ff ff    	jle    80491b2 <right_up+0x35>
 8049263:	8b 45 18             	mov    0x18(%ebp),%eax
 8049266:	89 04 24             	mov    %eax,(%esp)
 8049269:	e8 04 fa ff ff       	call   8048c72 <win>
 804926e:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 8049273:	89 c2                	mov    %eax,%edx
 8049275:	89 d0                	mov    %edx,%eax
 8049277:	c1 e0 02             	shl    $0x2,%eax
 804927a:	01 d0                	add    %edx,%eax
 804927c:	c1 e0 02             	shl    $0x2,%eax
 804927f:	03 45 1c             	add    0x1c(%ebp),%eax
 8049282:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 8049288:	8b 04 90             	mov    (%eax,%edx,4),%eax
 804928b:	a3 c0 d6 04 08       	mov    %eax,0x804d6c0
 8049290:	c9                   	leave  
 8049291:	c3                   	ret    

08049292 <left_down>:
 8049292:	55                   	push   %ebp
 8049293:	89 e5                	mov    %esp,%ebp
 8049295:	83 ec 18             	sub    $0x18,%esp
 8049298:	8b 45 08             	mov    0x8(%ebp),%eax
 804929b:	83 c0 01             	add    $0x1,%eax
 804929e:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 80492a3:	8b 45 0c             	mov    0xc(%ebp),%eax
 80492a6:	83 e8 01             	sub    $0x1,%eax
 80492a9:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 80492ae:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 80492b5:	00 00 00 
 80492b8:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 80492bf:	00 00 00 
 80492c2:	e9 a3 00 00 00       	jmp    804936a <left_down+0xd8>
 80492c7:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80492cd:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 80492d3:	89 d0                	mov    %edx,%eax
 80492d5:	c1 e0 04             	shl    $0x4,%eax
 80492d8:	29 d0                	sub    %edx,%eax
 80492da:	01 c8                	add    %ecx,%eax
 80492dc:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 80492e3:	3b 45 10             	cmp    0x10(%ebp),%eax
 80492e6:	75 0f                	jne    80492f7 <left_down+0x65>
 80492e8:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 80492ed:	83 c0 01             	add    $0x1,%eax
 80492f0:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 80492f5:	eb 59                	jmp    8049350 <left_down+0xbe>
 80492f7:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80492fd:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8049303:	89 d0                	mov    %edx,%eax
 8049305:	c1 e0 04             	shl    $0x4,%eax
 8049308:	29 d0                	sub    %edx,%eax
 804930a:	01 c8                	add    %ecx,%eax
 804930c:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8049313:	3b 45 14             	cmp    0x14(%ebp),%eax
 8049316:	75 0c                	jne    8049324 <left_down+0x92>
 8049318:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 804931f:	00 00 00 
 8049322:	eb 53                	jmp    8049377 <left_down+0xe5>
 8049324:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 804932a:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8049330:	89 d0                	mov    %edx,%eax
 8049332:	c1 e0 04             	shl    $0x4,%eax
 8049335:	29 d0                	sub    %edx,%eax
 8049337:	01 c8                	add    %ecx,%eax
 8049339:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8049340:	85 c0                	test   %eax,%eax
 8049342:	75 0c                	jne    8049350 <left_down+0xbe>
 8049344:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 804934b:	00 00 00 
 804934e:	eb 27                	jmp    8049377 <left_down+0xe5>
 8049350:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8049355:	83 c0 01             	add    $0x1,%eax
 8049358:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 804935d:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 8049362:	83 e8 01             	sub    $0x1,%eax
 8049365:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 804936a:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 804936f:	85 c0                	test   %eax,%eax
 8049371:	0f 89 50 ff ff ff    	jns    80492c7 <left_down+0x35>
 8049377:	8b 45 18             	mov    0x18(%ebp),%eax
 804937a:	89 04 24             	mov    %eax,(%esp)
 804937d:	e8 f0 f8 ff ff       	call   8048c72 <win>
 8049382:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 8049387:	89 c2                	mov    %eax,%edx
 8049389:	89 d0                	mov    %edx,%eax
 804938b:	c1 e0 02             	shl    $0x2,%eax
 804938e:	01 d0                	add    %edx,%eax
 8049390:	c1 e0 02             	shl    $0x2,%eax
 8049393:	03 45 1c             	add    0x1c(%ebp),%eax
 8049396:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 804939c:	8b 04 90             	mov    (%eax,%edx,4),%eax
 804939f:	a3 c4 d6 04 08       	mov    %eax,0x804d6c4
 80493a4:	c9                   	leave  
 80493a5:	c3                   	ret    

080493a6 <right_down>:
 80493a6:	55                   	push   %ebp
 80493a7:	89 e5                	mov    %esp,%ebp
 80493a9:	83 ec 18             	sub    $0x18,%esp
 80493ac:	8b 45 08             	mov    0x8(%ebp),%eax
 80493af:	83 c0 01             	add    $0x1,%eax
 80493b2:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 80493b7:	8b 45 0c             	mov    0xc(%ebp),%eax
 80493ba:	83 c0 01             	add    $0x1,%eax
 80493bd:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 80493c2:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 80493c9:	00 00 00 
 80493cc:	c7 05 a8 d6 04 08 00 	movl   $0x0,0x804d6a8
 80493d3:	00 00 00 
 80493d6:	e9 a3 00 00 00       	jmp    804947e <right_down+0xd8>
 80493db:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 80493e1:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 80493e7:	89 d0                	mov    %edx,%eax
 80493e9:	c1 e0 04             	shl    $0x4,%eax
 80493ec:	29 d0                	sub    %edx,%eax
 80493ee:	01 c8                	add    %ecx,%eax
 80493f0:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 80493f7:	3b 45 10             	cmp    0x10(%ebp),%eax
 80493fa:	75 0f                	jne    804940b <right_down+0x65>
 80493fc:	a1 a8 d6 04 08       	mov    0x804d6a8,%eax
 8049401:	83 c0 01             	add    $0x1,%eax
 8049404:	a3 a8 d6 04 08       	mov    %eax,0x804d6a8
 8049409:	eb 59                	jmp    8049464 <right_down+0xbe>
 804940b:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 8049411:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8049417:	89 d0                	mov    %edx,%eax
 8049419:	c1 e0 04             	shl    $0x4,%eax
 804941c:	29 d0                	sub    %edx,%eax
 804941e:	01 c8                	add    %ecx,%eax
 8049420:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8049427:	3b 45 14             	cmp    0x14(%ebp),%eax
 804942a:	75 0c                	jne    8049438 <right_down+0x92>
 804942c:	c7 05 a4 d6 04 08 00 	movl   $0x0,0x804d6a4
 8049433:	00 00 00 
 8049436:	eb 54                	jmp    804948c <right_down+0xe6>
 8049438:	8b 15 a0 d6 04 08    	mov    0x804d6a0,%edx
 804943e:	8b 0d 9c d6 04 08    	mov    0x804d69c,%ecx
 8049444:	89 d0                	mov    %edx,%eax
 8049446:	c1 e0 04             	shl    $0x4,%eax
 8049449:	29 d0                	sub    %edx,%eax
 804944b:	01 c8                	add    %ecx,%eax
 804944d:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 8049454:	85 c0                	test   %eax,%eax
 8049456:	75 0c                	jne    8049464 <right_down+0xbe>
 8049458:	c7 05 a4 d6 04 08 01 	movl   $0x1,0x804d6a4
 804945f:	00 00 00 
 8049462:	eb 28                	jmp    804948c <right_down+0xe6>
 8049464:	a1 9c d6 04 08       	mov    0x804d69c,%eax
 8049469:	83 c0 01             	add    $0x1,%eax
 804946c:	a3 9c d6 04 08       	mov    %eax,0x804d69c
 8049471:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 8049476:	83 c0 01             	add    $0x1,%eax
 8049479:	a3 a0 d6 04 08       	mov    %eax,0x804d6a0
 804947e:	a1 a0 d6 04 08       	mov    0x804d6a0,%eax
 8049483:	83 f8 0e             	cmp    $0xe,%eax
 8049486:	0f 8e 4f ff ff ff    	jle    80493db <right_down+0x35>
 804948c:	8b 45 18             	mov    0x18(%ebp),%eax
 804948f:	89 04 24             	mov    %eax,(%esp)
 8049492:	e8 db f7 ff ff       	call   8048c72 <win>
 8049497:	a1 a4 d6 04 08       	mov    0x804d6a4,%eax
 804949c:	89 c2                	mov    %eax,%edx
 804949e:	89 d0                	mov    %edx,%eax
 80494a0:	c1 e0 02             	shl    $0x2,%eax
 80494a3:	01 d0                	add    %edx,%eax
 80494a5:	c1 e0 02             	shl    $0x2,%eax
 80494a8:	03 45 1c             	add    0x1c(%ebp),%eax
 80494ab:	8b 15 a8 d6 04 08    	mov    0x804d6a8,%edx
 80494b1:	8b 04 90             	mov    (%eax,%edx,4),%eax
 80494b4:	a3 c8 d6 04 08       	mov    %eax,0x804d6c8
 80494b9:	c9                   	leave  
 80494ba:	c3                   	ret    

080494bb <get_player_win_table_max>:
 80494bb:	55                   	push   %ebp
 80494bc:	89 e5                	mov    %esp,%ebp
 80494be:	53                   	push   %ebx
 80494bf:	83 ec 34             	sub    $0x34,%esp
 80494c2:	c7 45 f4 70 a4 04 08 	movl   $0x804a470,-0xc(%ebp)
 80494c9:	c7 04 24 20 c8 04 08 	movl   $0x804c820,(%esp)
 80494d0:	e8 2f f7 ff ff       	call   8048c04 <reset>
 80494d5:	c7 05 94 d6 04 08 00 	movl   $0x0,0x804d694
 80494dc:	00 00 00 
 80494df:	e9 5e 02 00 00       	jmp    8049742 <get_player_win_table_max+0x287>
 80494e4:	c7 05 98 d6 04 08 00 	movl   $0x0,0x804d698
 80494eb:	00 00 00 
 80494ee:	e9 34 02 00 00       	jmp    8049727 <get_player_win_table_max+0x26c>
 80494f3:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80494f9:	8b 0d 94 d6 04 08    	mov    0x804d694,%ecx
 80494ff:	89 d0                	mov    %edx,%eax
 8049501:	c1 e0 04             	shl    $0x4,%eax
 8049504:	29 d0                	sub    %edx,%eax
 8049506:	01 c8                	add    %ecx,%eax
 8049508:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 804950f:	85 c0                	test   %eax,%eax
 8049511:	0f 85 b0 01 00 00    	jne    80496c7 <get_player_win_table_max+0x20c>
 8049517:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 804951d:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049522:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 8049529:	08 
 804952a:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 804952d:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 8049531:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 8049538:	00 
 8049539:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 8049540:	00 
 8049541:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049545:	89 04 24             	mov    %eax,(%esp)
 8049548:	e8 4e f7 ff ff       	call   8048c9b <left>
 804954d:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049553:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049558:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 804955f:	08 
 8049560:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049563:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 8049567:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 804956e:	00 
 804956f:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 8049576:	00 
 8049577:	89 54 24 04          	mov    %edx,0x4(%esp)
 804957b:	89 04 24             	mov    %eax,(%esp)
 804957e:	e8 0b f8 ff ff       	call   8048d8e <right>
 8049583:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049589:	a1 94 d6 04 08       	mov    0x804d694,%eax
 804958e:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 8049595:	08 
 8049596:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049599:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 804959d:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 80495a4:	00 
 80495a5:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 80495ac:	00 
 80495ad:	89 54 24 04          	mov    %edx,0x4(%esp)
 80495b1:	89 04 24             	mov    %eax,(%esp)
 80495b4:	e8 c9 f8 ff ff       	call   8048e82 <up>
 80495b9:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80495bf:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80495c4:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 80495cb:	08 
 80495cc:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80495cf:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 80495d3:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 80495da:	00 
 80495db:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 80495e2:	00 
 80495e3:	89 54 24 04          	mov    %edx,0x4(%esp)
 80495e7:	89 04 24             	mov    %eax,(%esp)
 80495ea:	e8 86 f9 ff ff       	call   8048f75 <down>
 80495ef:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80495f5:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80495fa:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 8049601:	08 
 8049602:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049605:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 8049609:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 8049610:	00 
 8049611:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 8049618:	00 
 8049619:	89 54 24 04          	mov    %edx,0x4(%esp)
 804961d:	89 04 24             	mov    %eax,(%esp)
 8049620:	e8 44 fa ff ff       	call   8049069 <left_up>
 8049625:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 804962b:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049630:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 8049637:	08 
 8049638:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 804963b:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 804963f:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 8049646:	00 
 8049647:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 804964e:	00 
 804964f:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049653:	89 04 24             	mov    %eax,(%esp)
 8049656:	e8 22 fb ff ff       	call   804917d <right_up>
 804965b:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049661:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049666:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 804966d:	08 
 804966e:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049671:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 8049675:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 804967c:	00 
 804967d:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 8049684:	00 
 8049685:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049689:	89 04 24             	mov    %eax,(%esp)
 804968c:	e8 01 fc ff ff       	call   8049292 <left_down>
 8049691:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049697:	a1 94 d6 04 08       	mov    0x804d694,%eax
 804969c:	c7 44 24 14 c0 c0 04 	movl   $0x804c0c0,0x14(%esp)
 80496a3:	08 
 80496a4:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80496a7:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 80496ab:	c7 44 24 0c 02 00 00 	movl   $0x2,0xc(%esp)
 80496b2:	00 
 80496b3:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
 80496ba:	00 
 80496bb:	89 54 24 04          	mov    %edx,0x4(%esp)
 80496bf:	89 04 24             	mov    %eax,(%esp)
 80496c2:	e8 df fc ff ff       	call   80493a6 <right_down>
 80496c7:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80496cd:	8b 1d 94 d6 04 08    	mov    0x804d694,%ebx
 80496d3:	8b 0d ac d6 04 08    	mov    0x804d6ac,%ecx
 80496d9:	a1 b0 d6 04 08       	mov    0x804d6b0,%eax
 80496de:	01 c1                	add    %eax,%ecx
 80496e0:	a1 b4 d6 04 08       	mov    0x804d6b4,%eax
 80496e5:	01 c1                	add    %eax,%ecx
 80496e7:	a1 b8 d6 04 08       	mov    0x804d6b8,%eax
 80496ec:	01 c1                	add    %eax,%ecx
 80496ee:	a1 bc d6 04 08       	mov    0x804d6bc,%eax
 80496f3:	01 c1                	add    %eax,%ecx
 80496f5:	a1 c0 d6 04 08       	mov    0x804d6c0,%eax
 80496fa:	01 c1                	add    %eax,%ecx
 80496fc:	a1 c4 d6 04 08       	mov    0x804d6c4,%eax
 8049701:	01 c1                	add    %eax,%ecx
 8049703:	a1 c8 d6 04 08       	mov    0x804d6c8,%eax
 8049708:	01 c1                	add    %eax,%ecx
 804970a:	89 d0                	mov    %edx,%eax
 804970c:	c1 e0 04             	shl    $0x4,%eax
 804970f:	29 d0                	sub    %edx,%eax
 8049711:	01 d8                	add    %ebx,%eax
 8049713:	89 0c 85 20 c8 04 08 	mov    %ecx,0x804c820(,%eax,4)
 804971a:	a1 98 d6 04 08       	mov    0x804d698,%eax
 804971f:	83 c0 01             	add    $0x1,%eax
 8049722:	a3 98 d6 04 08       	mov    %eax,0x804d698
 8049727:	a1 98 d6 04 08       	mov    0x804d698,%eax
 804972c:	83 f8 0e             	cmp    $0xe,%eax
 804972f:	0f 8e be fd ff ff    	jle    80494f3 <get_player_win_table_max+0x38>
 8049735:	a1 94 d6 04 08       	mov    0x804d694,%eax
 804973a:	83 c0 01             	add    $0x1,%eax
 804973d:	a3 94 d6 04 08       	mov    %eax,0x804d694
 8049742:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049747:	83 f8 0e             	cmp    $0xe,%eax
 804974a:	0f 8e 94 fd ff ff    	jle    80494e4 <get_player_win_table_max+0x29>
 8049750:	a1 20 c8 04 08       	mov    0x804c820,%eax
 8049755:	a3 e0 d6 04 08       	mov    %eax,0x804d6e0
 804975a:	c7 05 94 d6 04 08 00 	movl   $0x0,0x804d694
 8049761:	00 00 00 
 8049764:	e9 8a 00 00 00       	jmp    80497f3 <get_player_win_table_max+0x338>
 8049769:	c7 05 98 d6 04 08 00 	movl   $0x0,0x804d698
 8049770:	00 00 00 
 8049773:	eb 67                	jmp    80497dc <get_player_win_table_max+0x321>
 8049775:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 804977b:	8b 0d 94 d6 04 08    	mov    0x804d694,%ecx
 8049781:	89 d0                	mov    %edx,%eax
 8049783:	c1 e0 04             	shl    $0x4,%eax
 8049786:	29 d0                	sub    %edx,%eax
 8049788:	01 c8                	add    %ecx,%eax
 804978a:	8b 14 85 20 c8 04 08 	mov    0x804c820(,%eax,4),%edx
 8049791:	a1 e0 d6 04 08       	mov    0x804d6e0,%eax
 8049796:	39 c2                	cmp    %eax,%edx
 8049798:	7e 35                	jle    80497cf <get_player_win_table_max+0x314>
 804979a:	a1 98 d6 04 08       	mov    0x804d698,%eax
 804979f:	a3 84 d6 04 08       	mov    %eax,0x804d684
 80497a4:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80497a9:	a3 88 d6 04 08       	mov    %eax,0x804d688
 80497ae:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80497b4:	8b 0d 94 d6 04 08    	mov    0x804d694,%ecx
 80497ba:	89 d0                	mov    %edx,%eax
 80497bc:	c1 e0 04             	shl    $0x4,%eax
 80497bf:	29 d0                	sub    %edx,%eax
 80497c1:	01 c8                	add    %ecx,%eax
 80497c3:	8b 04 85 20 c8 04 08 	mov    0x804c820(,%eax,4),%eax
 80497ca:	a3 e0 d6 04 08       	mov    %eax,0x804d6e0
 80497cf:	a1 98 d6 04 08       	mov    0x804d698,%eax
 80497d4:	83 c0 01             	add    $0x1,%eax
 80497d7:	a3 98 d6 04 08       	mov    %eax,0x804d698
 80497dc:	a1 98 d6 04 08       	mov    0x804d698,%eax
 80497e1:	83 f8 0e             	cmp    $0xe,%eax
 80497e4:	7e 8f                	jle    8049775 <get_player_win_table_max+0x2ba>
 80497e6:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80497eb:	83 c0 01             	add    $0x1,%eax
 80497ee:	a3 94 d6 04 08       	mov    %eax,0x804d694
 80497f3:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80497f8:	83 f8 0e             	cmp    $0xe,%eax
 80497fb:	0f 8e 68 ff ff ff    	jle    8049769 <get_player_win_table_max+0x2ae>
 8049801:	83 c4 34             	add    $0x34,%esp
 8049804:	5b                   	pop    %ebx
 8049805:	5d                   	pop    %ebp
 8049806:	c3                   	ret    

08049807 <get_computer_win_table_max>:
 8049807:	55                   	push   %ebp
 8049808:	89 e5                	mov    %esp,%ebp
 804980a:	53                   	push   %ebx
 804980b:	83 ec 34             	sub    $0x34,%esp
 804980e:	c7 45 f4 7b a4 04 08 	movl   $0x804a47b,-0xc(%ebp)
 8049815:	c7 04 24 c0 cb 04 08 	movl   $0x804cbc0,(%esp)
 804981c:	e8 e3 f3 ff ff       	call   8048c04 <reset>
 8049821:	c7 05 94 d6 04 08 00 	movl   $0x0,0x804d694
 8049828:	00 00 00 
 804982b:	e9 5e 02 00 00       	jmp    8049a8e <get_computer_win_table_max+0x287>
 8049830:	c7 05 98 d6 04 08 00 	movl   $0x0,0x804d698
 8049837:	00 00 00 
 804983a:	e9 34 02 00 00       	jmp    8049a73 <get_computer_win_table_max+0x26c>
 804983f:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049845:	8b 0d 94 d6 04 08    	mov    0x804d694,%ecx
 804984b:	89 d0                	mov    %edx,%eax
 804984d:	c1 e0 04             	shl    $0x4,%eax
 8049850:	29 d0                	sub    %edx,%eax
 8049852:	01 c8                	add    %ecx,%eax
 8049854:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 804985b:	85 c0                	test   %eax,%eax
 804985d:	0f 85 b0 01 00 00    	jne    8049a13 <get_computer_win_table_max+0x20c>
 8049863:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049869:	a1 94 d6 04 08       	mov    0x804d694,%eax
 804986e:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 8049875:	08 
 8049876:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049879:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 804987d:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 8049884:	00 
 8049885:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 804988c:	00 
 804988d:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049891:	89 04 24             	mov    %eax,(%esp)
 8049894:	e8 02 f4 ff ff       	call   8048c9b <left>
 8049899:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 804989f:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80498a4:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 80498ab:	08 
 80498ac:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80498af:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 80498b3:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 80498ba:	00 
 80498bb:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 80498c2:	00 
 80498c3:	89 54 24 04          	mov    %edx,0x4(%esp)
 80498c7:	89 04 24             	mov    %eax,(%esp)
 80498ca:	e8 bf f4 ff ff       	call   8048d8e <right>
 80498cf:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80498d5:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80498da:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 80498e1:	08 
 80498e2:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80498e5:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 80498e9:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 80498f0:	00 
 80498f1:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 80498f8:	00 
 80498f9:	89 54 24 04          	mov    %edx,0x4(%esp)
 80498fd:	89 04 24             	mov    %eax,(%esp)
 8049900:	e8 7d f5 ff ff       	call   8048e82 <up>
 8049905:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 804990b:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049910:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 8049917:	08 
 8049918:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 804991b:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 804991f:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 8049926:	00 
 8049927:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 804992e:	00 
 804992f:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049933:	89 04 24             	mov    %eax,(%esp)
 8049936:	e8 3a f6 ff ff       	call   8048f75 <down>
 804993b:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049941:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049946:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 804994d:	08 
 804994e:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049951:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 8049955:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 804995c:	00 
 804995d:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 8049964:	00 
 8049965:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049969:	89 04 24             	mov    %eax,(%esp)
 804996c:	e8 f8 f6 ff ff       	call   8049069 <left_up>
 8049971:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049977:	a1 94 d6 04 08       	mov    0x804d694,%eax
 804997c:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 8049983:	08 
 8049984:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049987:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 804998b:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 8049992:	00 
 8049993:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 804999a:	00 
 804999b:	89 54 24 04          	mov    %edx,0x4(%esp)
 804999f:	89 04 24             	mov    %eax,(%esp)
 80499a2:	e8 d6 f7 ff ff       	call   804917d <right_up>
 80499a7:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80499ad:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80499b2:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 80499b9:	08 
 80499ba:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80499bd:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 80499c1:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 80499c8:	00 
 80499c9:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 80499d0:	00 
 80499d1:	89 54 24 04          	mov    %edx,0x4(%esp)
 80499d5:	89 04 24             	mov    %eax,(%esp)
 80499d8:	e8 b5 f8 ff ff       	call   8049292 <left_down>
 80499dd:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 80499e3:	a1 94 d6 04 08       	mov    0x804d694,%eax
 80499e8:	c7 44 24 14 80 c0 04 	movl   $0x804c080,0x14(%esp)
 80499ef:	08 
 80499f0:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80499f3:	89 4c 24 10          	mov    %ecx,0x10(%esp)
 80499f7:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 80499fe:	00 
 80499ff:	c7 44 24 08 02 00 00 	movl   $0x2,0x8(%esp)
 8049a06:	00 
 8049a07:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049a0b:	89 04 24             	mov    %eax,(%esp)
 8049a0e:	e8 93 f9 ff ff       	call   80493a6 <right_down>
 8049a13:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049a19:	8b 1d 94 d6 04 08    	mov    0x804d694,%ebx
 8049a1f:	8b 0d ac d6 04 08    	mov    0x804d6ac,%ecx
 8049a25:	a1 b0 d6 04 08       	mov    0x804d6b0,%eax
 8049a2a:	01 c1                	add    %eax,%ecx
 8049a2c:	a1 b4 d6 04 08       	mov    0x804d6b4,%eax
 8049a31:	01 c1                	add    %eax,%ecx
 8049a33:	a1 b8 d6 04 08       	mov    0x804d6b8,%eax
 8049a38:	01 c1                	add    %eax,%ecx
 8049a3a:	a1 bc d6 04 08       	mov    0x804d6bc,%eax
 8049a3f:	01 c1                	add    %eax,%ecx
 8049a41:	a1 c0 d6 04 08       	mov    0x804d6c0,%eax
 8049a46:	01 c1                	add    %eax,%ecx
 8049a48:	a1 c4 d6 04 08       	mov    0x804d6c4,%eax
 8049a4d:	01 c1                	add    %eax,%ecx
 8049a4f:	a1 c8 d6 04 08       	mov    0x804d6c8,%eax
 8049a54:	01 c1                	add    %eax,%ecx
 8049a56:	89 d0                	mov    %edx,%eax
 8049a58:	c1 e0 04             	shl    $0x4,%eax
 8049a5b:	29 d0                	sub    %edx,%eax
 8049a5d:	01 d8                	add    %ebx,%eax
 8049a5f:	89 0c 85 c0 cb 04 08 	mov    %ecx,0x804cbc0(,%eax,4)
 8049a66:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8049a6b:	83 c0 01             	add    $0x1,%eax
 8049a6e:	a3 98 d6 04 08       	mov    %eax,0x804d698
 8049a73:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8049a78:	83 f8 0e             	cmp    $0xe,%eax
 8049a7b:	0f 8e be fd ff ff    	jle    804983f <get_computer_win_table_max+0x38>
 8049a81:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049a86:	83 c0 01             	add    $0x1,%eax
 8049a89:	a3 94 d6 04 08       	mov    %eax,0x804d694
 8049a8e:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049a93:	83 f8 0e             	cmp    $0xe,%eax
 8049a96:	0f 8e 94 fd ff ff    	jle    8049830 <get_computer_win_table_max+0x29>
 8049a9c:	a1 c0 cb 04 08       	mov    0x804cbc0,%eax
 8049aa1:	a3 00 d7 04 08       	mov    %eax,0x804d700
 8049aa6:	c7 05 94 d6 04 08 00 	movl   $0x0,0x804d694
 8049aad:	00 00 00 
 8049ab0:	e9 8a 00 00 00       	jmp    8049b3f <get_computer_win_table_max+0x338>
 8049ab5:	c7 05 98 d6 04 08 00 	movl   $0x0,0x804d698
 8049abc:	00 00 00 
 8049abf:	eb 67                	jmp    8049b28 <get_computer_win_table_max+0x321>
 8049ac1:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049ac7:	8b 0d 94 d6 04 08    	mov    0x804d694,%ecx
 8049acd:	89 d0                	mov    %edx,%eax
 8049acf:	c1 e0 04             	shl    $0x4,%eax
 8049ad2:	29 d0                	sub    %edx,%eax
 8049ad4:	01 c8                	add    %ecx,%eax
 8049ad6:	8b 14 85 c0 cb 04 08 	mov    0x804cbc0(,%eax,4),%edx
 8049add:	a1 00 d7 04 08       	mov    0x804d700,%eax
 8049ae2:	39 c2                	cmp    %eax,%edx
 8049ae4:	7e 35                	jle    8049b1b <get_computer_win_table_max+0x314>
 8049ae6:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8049aeb:	a3 8c d6 04 08       	mov    %eax,0x804d68c
 8049af0:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049af5:	a3 90 d6 04 08       	mov    %eax,0x804d690
 8049afa:	8b 15 98 d6 04 08    	mov    0x804d698,%edx
 8049b00:	8b 0d 94 d6 04 08    	mov    0x804d694,%ecx
 8049b06:	89 d0                	mov    %edx,%eax
 8049b08:	c1 e0 04             	shl    $0x4,%eax
 8049b0b:	29 d0                	sub    %edx,%eax
 8049b0d:	01 c8                	add    %ecx,%eax
 8049b0f:	8b 04 85 c0 cb 04 08 	mov    0x804cbc0(,%eax,4),%eax
 8049b16:	a3 00 d7 04 08       	mov    %eax,0x804d700
 8049b1b:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8049b20:	83 c0 01             	add    $0x1,%eax
 8049b23:	a3 98 d6 04 08       	mov    %eax,0x804d698
 8049b28:	a1 98 d6 04 08       	mov    0x804d698,%eax
 8049b2d:	83 f8 0e             	cmp    $0xe,%eax
 8049b30:	7e 8f                	jle    8049ac1 <get_computer_win_table_max+0x2ba>
 8049b32:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049b37:	83 c0 01             	add    $0x1,%eax
 8049b3a:	a3 94 d6 04 08       	mov    %eax,0x804d694
 8049b3f:	a1 94 d6 04 08       	mov    0x804d694,%eax
 8049b44:	83 f8 0e             	cmp    $0xe,%eax
 8049b47:	0f 8e 68 ff ff ff    	jle    8049ab5 <get_computer_win_table_max+0x2ae>
 8049b4d:	83 c4 34             	add    $0x34,%esp
 8049b50:	5b                   	pop    %ebx
 8049b51:	5d                   	pop    %ebp
 8049b52:	c3                   	ret    
 8049b53:	90                   	nop

08049b54 <main>:
 8049b54:	55                   	push   %ebp
 8049b55:	89 e5                	mov    %esp,%ebp
 8049b57:	83 e4 f0             	and    $0xfffffff0,%esp
 8049b5a:	81 ec e0 00 00 00    	sub    $0xe0,%esp
 8049b60:	c7 84 24 d0 00 00 00 	movl   $0xffffffff,0xd0(%esp)
 8049b67:	ff ff ff ff 
 8049b6b:	c7 44 24 04 02 00 00 	movl   $0x2,0x4(%esp)
 8049b72:	00 
 8049b73:	c7 04 24 86 a4 04 08 	movl   $0x804a486,(%esp)
 8049b7a:	e8 0d e9 ff ff       	call   804848c <open@plt>
 8049b7f:	89 84 24 dc 00 00 00 	mov    %eax,0xdc(%esp)
 8049b86:	83 bc 24 dc 00 00 00 	cmpl   $0x0,0xdc(%esp)
 8049b8d:	00 
 8049b8e:	79 18                	jns    8049ba8 <main+0x54>
 8049b90:	c7 04 24 8f a4 04 08 	movl   $0x804a48f,(%esp)
 8049b97:	e8 80 e9 ff ff       	call   804851c <puts@plt>
 8049b9c:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8049ba3:	e8 94 e9 ff ff       	call   804853c <exit@plt>
 8049ba8:	8d 44 24 28          	lea    0x28(%esp),%eax
 8049bac:	89 44 24 08          	mov    %eax,0x8(%esp)
 8049bb0:	c7 44 24 04 00 46 00 	movl   $0x4600,0x4(%esp)
 8049bb7:	00 
 8049bb8:	8b 84 24 dc 00 00 00 	mov    0xdc(%esp),%eax
 8049bbf:	89 04 24             	mov    %eax,(%esp)
 8049bc2:	e8 25 e9 ff ff       	call   80484ec <ioctl@plt>
 8049bc7:	8b 44 24 28          	mov    0x28(%esp),%eax
 8049bcb:	a3 e4 d6 04 08       	mov    %eax,0x804d6e4
 8049bd0:	8b 44 24 2c          	mov    0x2c(%esp),%eax
 8049bd4:	a3 ec d6 04 08       	mov    %eax,0x804d6ec
 8049bd9:	8b 44 24 40          	mov    0x40(%esp),%eax
 8049bdd:	89 84 24 d4 00 00 00 	mov    %eax,0xd4(%esp)
 8049be4:	8b 0d ec d6 04 08    	mov    0x804d6ec,%ecx
 8049bea:	8b 15 e4 d6 04 08    	mov    0x804d6e4,%edx
 8049bf0:	b8 9f a4 04 08       	mov    $0x804a49f,%eax
 8049bf5:	89 4c 24 08          	mov    %ecx,0x8(%esp)
 8049bf9:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049bfd:	89 04 24             	mov    %eax,(%esp)
 8049c00:	e8 07 e9 ff ff       	call   804850c <printf@plt>
 8049c05:	b8 b4 a4 04 08       	mov    $0x804a4b4,%eax
 8049c0a:	8b 94 24 d4 00 00 00 	mov    0xd4(%esp),%edx
 8049c11:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049c15:	89 04 24             	mov    %eax,(%esp)
 8049c18:	e8 ef e8 ff ff       	call   804850c <printf@plt>
 8049c1d:	8b 15 e4 d6 04 08    	mov    0x804d6e4,%edx
 8049c23:	a1 ec d6 04 08       	mov    0x804d6ec,%eax
 8049c28:	0f af c2             	imul   %edx,%eax
 8049c2b:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049c32:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
 8049c39:	00 
 8049c3a:	8b 84 24 dc 00 00 00 	mov    0xdc(%esp),%eax
 8049c41:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049c45:	c7 44 24 0c 01 00 00 	movl   $0x1,0xc(%esp)
 8049c4c:	00 
 8049c4d:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 8049c54:	00 
 8049c55:	89 54 24 04          	mov    %edx,0x4(%esp)
 8049c59:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8049c60:	e8 37 e8 ff ff       	call   804849c <mmap@plt>
 8049c65:	a3 e8 d6 04 08       	mov    %eax,0x804d6e8
 8049c6a:	c7 44 24 08 82 dc ee 	movl   $0xeedc82,0x8(%esp)
 8049c71:	00 
 8049c72:	c7 44 24 04 46 00 00 	movl   $0x46,0x4(%esp)
 8049c79:	00 
 8049c7a:	c7 04 24 6c 02 00 00 	movl   $0x26c,(%esp)
 8049c81:	e8 6d ed ff ff       	call   80489f3 <fb_bg>
 8049c86:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
 8049c8d:	00 
 8049c8e:	c7 44 24 04 64 00 00 	movl   $0x64,0x4(%esp)
 8049c95:	00 
 8049c96:	c7 04 24 8a 02 00 00 	movl   $0x28a,(%esp)
 8049c9d:	e8 8a ec ff ff       	call   804892c <fb_grid>
 8049ca2:	c7 44 24 04 7c 01 00 	movl   $0x17c,0x4(%esp)
 8049ca9:	00 
 8049caa:	c7 04 24 a2 03 00 00 	movl   $0x3a2,(%esp)
 8049cb1:	e8 a2 eb ff ff       	call   8048858 <fb_small_black_point>
 8049cb6:	c7 44 24 04 dc 00 00 	movl   $0xdc,0x4(%esp)
 8049cbd:	00 
 8049cbe:	c7 04 24 02 03 00 00 	movl   $0x302,(%esp)
 8049cc5:	e8 8e eb ff ff       	call   8048858 <fb_small_black_point>
 8049cca:	c7 44 24 04 dc 00 00 	movl   $0xdc,0x4(%esp)
 8049cd1:	00 
 8049cd2:	c7 04 24 42 04 00 00 	movl   $0x442,(%esp)
 8049cd9:	e8 7a eb ff ff       	call   8048858 <fb_small_black_point>
 8049cde:	c7 44 24 04 1c 02 00 	movl   $0x21c,0x4(%esp)
 8049ce5:	00 
 8049ce6:	c7 04 24 02 03 00 00 	movl   $0x302,(%esp)
 8049ced:	e8 66 eb ff ff       	call   8048858 <fb_small_black_point>
 8049cf2:	c7 44 24 04 1c 02 00 	movl   $0x21c,0x4(%esp)
 8049cf9:	00 
 8049cfa:	c7 04 24 42 04 00 00 	movl   $0x442,(%esp)
 8049d01:	e8 52 eb ff ff       	call   8048858 <fb_small_black_point>
 8049d06:	c7 44 24 04 7c 01 00 	movl   $0x17c,0x4(%esp)
 8049d0d:	00 
 8049d0e:	c7 04 24 a2 03 00 00 	movl   $0x3a2,(%esp)
 8049d15:	e8 c9 eb ff ff       	call   80488e3 <fb_black_point>
 8049d1a:	c7 05 40 c6 04 08 02 	movl   $0x2,0x804c640
 8049d21:	00 00 00 
 8049d24:	a1 60 c0 04 08       	mov    0x804c060,%eax
 8049d29:	89 c2                	mov    %eax,%edx
 8049d2b:	83 c0 01             	add    $0x1,%eax
 8049d2e:	a3 60 c0 04 08       	mov    %eax,0x804c060
 8049d33:	c7 44 24 0c ff ff ff 	movl   $0xffffff,0xc(%esp)
 8049d3a:	00 
 8049d3b:	c7 44 24 08 7c 01 00 	movl   $0x17c,0x8(%esp)
 8049d42:	00 
 8049d43:	c7 44 24 04 a2 03 00 	movl   $0x3a2,0x4(%esp)
 8049d4a:	00 
 8049d4b:	89 14 24             	mov    %edx,(%esp)
 8049d4e:	e8 0d ed ff ff       	call   8048a60 <fb_num>
 8049d53:	e8 78 00 00 00       	call   8049dd0 <open_mouse>
 8049d58:	89 84 24 d8 00 00 00 	mov    %eax,0xd8(%esp)
 8049d5f:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 8049d64:	89 c2                	mov    %eax,%edx
 8049d66:	c1 ea 1f             	shr    $0x1f,%edx
 8049d69:	8d 04 02             	lea    (%edx,%eax,1),%eax
 8049d6c:	d1 f8                	sar    %eax
 8049d6e:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 8049d73:	a1 ec d6 04 08       	mov    0x804d6ec,%eax
 8049d78:	89 c2                	mov    %eax,%edx
 8049d7a:	c1 ea 1f             	shr    $0x1f,%edx
 8049d7d:	8d 04 02             	lea    (%edx,%eax,1),%eax
 8049d80:	d1 f8                	sar    %eax
 8049d82:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 8049d87:	eb 01                	jmp    8049d8a <main+0x236>
 8049d89:	90                   	nop
 8049d8a:	8d 84 24 d8 00 00 00 	lea    0xd8(%esp),%eax
 8049d91:	89 04 24             	mov    %eax,(%esp)
 8049d94:	e8 da 01 00 00       	call   8049f73 <move_mouse>
 8049d99:	8d 84 24 d0 00 00 00 	lea    0xd0(%esp),%eax
 8049da0:	89 44 24 04          	mov    %eax,0x4(%esp)
 8049da4:	8d 84 24 d8 00 00 00 	lea    0xd8(%esp),%eax
 8049dab:	89 04 24             	mov    %eax,(%esp)
 8049dae:	e8 f1 03 00 00       	call   804a1a4 <player>
 8049db3:	8b 84 24 d0 00 00 00 	mov    0xd0(%esp),%eax
 8049dba:	85 c0                	test   %eax,%eax
 8049dbc:	75 cb                	jne    8049d89 <main+0x235>
 8049dbe:	e8 41 e8 ff ff       	call   8048604 <computer>
 8049dc3:	c7 84 24 d0 00 00 00 	movl   $0xffffffff,0xd0(%esp)
 8049dca:	ff ff ff ff 
 8049dce:	eb ba                	jmp    8049d8a <main+0x236>

08049dd0 <open_mouse>:
 8049dd0:	55                   	push   %ebp
 8049dd1:	89 e5                	mov    %esp,%ebp
 8049dd3:	83 ec 28             	sub    $0x28,%esp
 8049dd6:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 8049ddd:	00 
 8049dde:	c7 04 24 bd a4 04 08 	movl   $0x804a4bd,(%esp)
 8049de5:	e8 a2 e6 ff ff       	call   804848c <open@plt>
 8049dea:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049ded:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8049df1:	79 13                	jns    8049e06 <open_mouse+0x36>
 8049df3:	c7 04 24 cd a4 04 08 	movl   $0x804a4cd,(%esp)
 8049dfa:	e8 1d e7 ff ff       	call   804851c <puts@plt>
 8049dff:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049e04:	eb 03                	jmp    8049e09 <open_mouse+0x39>
 8049e06:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049e09:	c9                   	leave  
 8049e0a:	c3                   	ret    

08049e0b <read_mouse>:
 8049e0b:	55                   	push   %ebp
 8049e0c:	89 e5                	mov    %esp,%ebp
 8049e0e:	83 ec 28             	sub    $0x28,%esp
 8049e11:	c7 45 ec ff ff ff ff 	movl   $0xffffffff,-0x14(%ebp)
 8049e18:	c7 44 24 08 08 00 00 	movl   $0x8,0x8(%esp)
 8049e1f:	00 
 8049e20:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 8049e27:	00 
 8049e28:	c7 04 24 04 c8 04 08 	movl   $0x804c804,(%esp)
 8049e2f:	e8 88 e6 ff ff       	call   80484bc <memset@plt>
 8049e34:	8b 45 08             	mov    0x8(%ebp),%eax
 8049e37:	8b 00                	mov    (%eax),%eax
 8049e39:	c7 44 24 08 08 00 00 	movl   $0x8,0x8(%esp)
 8049e40:	00 
 8049e41:	c7 44 24 04 04 c8 04 	movl   $0x804c804,0x4(%esp)
 8049e48:	08 
 8049e49:	89 04 24             	mov    %eax,(%esp)
 8049e4c:	e8 8b e6 ff ff       	call   80484dc <read@plt>
 8049e51:	0f b6 05 05 c8 04 08 	movzbl 0x804c805,%eax
 8049e58:	0f be c0             	movsbl %al,%eax
 8049e5b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049e5e:	0f b6 05 06 c8 04 08 	movzbl 0x804c806,%eax
 8049e65:	0f be c0             	movsbl %al,%eax
 8049e68:	f7 d8                	neg    %eax
 8049e6a:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049e6d:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 8049e72:	03 45 f4             	add    -0xc(%ebp),%eax
 8049e75:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 8049e7a:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 8049e7f:	03 45 f0             	add    -0x10(%ebp),%eax
 8049e82:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 8049e87:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 8049e8c:	85 c0                	test   %eax,%eax
 8049e8e:	79 0a                	jns    8049e9a <read_mouse+0x8f>
 8049e90:	c7 05 f4 d6 04 08 00 	movl   $0x0,0x804d6f4
 8049e97:	00 00 00 
 8049e9a:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 8049e9f:	8d 50 f6             	lea    -0xa(%eax),%edx
 8049ea2:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 8049ea7:	39 c2                	cmp    %eax,%edx
 8049ea9:	7d 0d                	jge    8049eb8 <read_mouse+0xad>
 8049eab:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 8049eb0:	83 e8 0a             	sub    $0xa,%eax
 8049eb3:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 8049eb8:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 8049ebd:	85 c0                	test   %eax,%eax
 8049ebf:	79 0a                	jns    8049ecb <read_mouse+0xc0>
 8049ec1:	c7 05 fc d6 04 08 00 	movl   $0x0,0x804d6fc
 8049ec8:	00 00 00 
 8049ecb:	a1 ec d6 04 08       	mov    0x804d6ec,%eax
 8049ed0:	8d 50 ef             	lea    -0x11(%eax),%edx
 8049ed3:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 8049ed8:	39 c2                	cmp    %eax,%edx
 8049eda:	7d 0d                	jge    8049ee9 <read_mouse+0xde>
 8049edc:	a1 ec d6 04 08       	mov    0x804d6ec,%eax
 8049ee1:	83 e8 11             	sub    $0x11,%eax
 8049ee4:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 8049ee9:	c9                   	leave  
 8049eea:	c3                   	ret    

08049eeb <fb_mouse>:
 8049eeb:	55                   	push   %ebp
 8049eec:	89 e5                	mov    %esp,%ebp
 8049eee:	83 ec 10             	sub    $0x10,%esp
 8049ef1:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
 8049ef8:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 8049eff:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 8049f06:	eb 63                	jmp    8049f6b <fb_mouse+0x80>
 8049f08:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
 8049f0f:	eb 4c                	jmp    8049f5d <fb_mouse+0x72>
 8049f11:	8b 55 f8             	mov    -0x8(%ebp),%edx
 8049f14:	89 d0                	mov    %edx,%eax
 8049f16:	c1 e0 02             	shl    $0x2,%eax
 8049f19:	01 d0                	add    %edx,%eax
 8049f1b:	01 c0                	add    %eax,%eax
 8049f1d:	03 45 fc             	add    -0x4(%ebp),%eax
 8049f20:	8b 04 85 00 c1 04 08 	mov    0x804c100(,%eax,4),%eax
 8049f27:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049f2a:	81 7d f4 00 00 ff 00 	cmpl   $0xff0000,-0xc(%ebp)
 8049f31:	74 26                	je     8049f59 <fb_mouse+0x6e>
 8049f33:	8b 15 e8 d6 04 08    	mov    0x804d6e8,%edx
 8049f39:	a1 e4 d6 04 08       	mov    0x804d6e4,%eax
 8049f3e:	0f af 45 0c          	imul   0xc(%ebp),%eax
 8049f42:	89 c1                	mov    %eax,%ecx
 8049f44:	8b 45 08             	mov    0x8(%ebp),%eax
 8049f47:	01 c1                	add    %eax,%ecx
 8049f49:	8b 45 fc             	mov    -0x4(%ebp),%eax
 8049f4c:	8d 04 01             	lea    (%ecx,%eax,1),%eax
 8049f4f:	c1 e0 02             	shl    $0x2,%eax
 8049f52:	01 c2                	add    %eax,%edx
 8049f54:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049f57:	89 02                	mov    %eax,(%edx)
 8049f59:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
 8049f5d:	83 7d fc 09          	cmpl   $0x9,-0x4(%ebp)
 8049f61:	7e ae                	jle    8049f11 <fb_mouse+0x26>
 8049f63:	83 45 0c 01          	addl   $0x1,0xc(%ebp)
 8049f67:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
 8049f6b:	83 7d f8 10          	cmpl   $0x10,-0x8(%ebp)
 8049f6f:	7e 97                	jle    8049f08 <fb_mouse+0x1d>
 8049f71:	c9                   	leave  
 8049f72:	c3                   	ret    

08049f73 <move_mouse>:
 8049f73:	55                   	push   %ebp
 8049f74:	89 e5                	mov    %esp,%ebp
 8049f76:	53                   	push   %ebx
 8049f77:	83 ec 24             	sub    $0x24,%esp
 8049f7a:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 8049f81:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 8049f86:	a3 f0 d6 04 08       	mov    %eax,0x804d6f0
 8049f8b:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 8049f90:	a3 f8 d6 04 08       	mov    %eax,0x804d6f8
 8049f95:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 8049f9c:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 8049fa3:	eb 5e                	jmp    804a003 <move_mouse+0x90>
 8049fa5:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8049fac:	eb 3e                	jmp    8049fec <move_mouse+0x79>
 8049fae:	8b 45 ec             	mov    -0x14(%ebp),%eax
 8049fb1:	8b 15 e8 d6 04 08    	mov    0x804d6e8,%edx
 8049fb7:	8b 1d fc d6 04 08    	mov    0x804d6fc,%ebx
 8049fbd:	8b 0d e4 d6 04 08    	mov    0x804d6e4,%ecx
 8049fc3:	0f af cb             	imul   %ebx,%ecx
 8049fc6:	89 cb                	mov    %ecx,%ebx
 8049fc8:	8b 0d f4 d6 04 08    	mov    0x804d6f4,%ecx
 8049fce:	01 cb                	add    %ecx,%ebx
 8049fd0:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049fd3:	8d 0c 0b             	lea    (%ebx,%ecx,1),%ecx
 8049fd6:	c1 e1 02             	shl    $0x2,%ecx
 8049fd9:	01 ca                	add    %ecx,%edx
 8049fdb:	8b 12                	mov    (%edx),%edx
 8049fdd:	89 14 85 20 d7 04 08 	mov    %edx,0x804d720(,%eax,4)
 8049fe4:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 8049fe8:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8049fec:	83 7d f4 09          	cmpl   $0x9,-0xc(%ebp)
 8049ff0:	7e bc                	jle    8049fae <move_mouse+0x3b>
 8049ff2:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 8049ff7:	83 c0 01             	add    $0x1,%eax
 8049ffa:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 8049fff:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 804a003:	83 7d f0 10          	cmpl   $0x10,-0x10(%ebp)
 804a007:	7e 9c                	jle    8049fa5 <move_mouse+0x32>
 804a009:	a1 f0 d6 04 08       	mov    0x804d6f0,%eax
 804a00e:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 804a013:	a1 f8 d6 04 08       	mov    0x804d6f8,%eax
 804a018:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 804a01d:	8b 15 fc d6 04 08    	mov    0x804d6fc,%edx
 804a023:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a028:	89 54 24 04          	mov    %edx,0x4(%esp)
 804a02c:	89 04 24             	mov    %eax,(%esp)
 804a02f:	e8 b7 fe ff ff       	call   8049eeb <fb_mouse>
 804a034:	8b 45 08             	mov    0x8(%ebp),%eax
 804a037:	89 04 24             	mov    %eax,(%esp)
 804a03a:	e8 cc fd ff ff       	call   8049e0b <read_mouse>
 804a03f:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 804a046:	c7 45 f0 00 00 00 00 	movl   $0x0,-0x10(%ebp)
 804a04d:	eb 5e                	jmp    804a0ad <move_mouse+0x13a>
 804a04f:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 804a056:	eb 3e                	jmp    804a096 <move_mouse+0x123>
 804a058:	a1 e8 d6 04 08       	mov    0x804d6e8,%eax
 804a05d:	8b 0d f8 d6 04 08    	mov    0x804d6f8,%ecx
 804a063:	8b 15 e4 d6 04 08    	mov    0x804d6e4,%edx
 804a069:	0f af d1             	imul   %ecx,%edx
 804a06c:	89 d1                	mov    %edx,%ecx
 804a06e:	8b 15 f0 d6 04 08    	mov    0x804d6f0,%edx
 804a074:	01 d1                	add    %edx,%ecx
 804a076:	8b 55 f4             	mov    -0xc(%ebp),%edx
 804a079:	8d 14 11             	lea    (%ecx,%edx,1),%edx
 804a07c:	c1 e2 02             	shl    $0x2,%edx
 804a07f:	8d 14 10             	lea    (%eax,%edx,1),%edx
 804a082:	8b 45 ec             	mov    -0x14(%ebp),%eax
 804a085:	8b 04 85 20 d7 04 08 	mov    0x804d720(,%eax,4),%eax
 804a08c:	89 02                	mov    %eax,(%edx)
 804a08e:	83 45 ec 01          	addl   $0x1,-0x14(%ebp)
 804a092:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 804a096:	83 7d f4 09          	cmpl   $0x9,-0xc(%ebp)
 804a09a:	7e bc                	jle    804a058 <move_mouse+0xe5>
 804a09c:	a1 f8 d6 04 08       	mov    0x804d6f8,%eax
 804a0a1:	83 c0 01             	add    $0x1,%eax
 804a0a4:	a3 f8 d6 04 08       	mov    %eax,0x804d6f8
 804a0a9:	83 45 f0 01          	addl   $0x1,-0x10(%ebp)
 804a0ad:	83 7d f0 10          	cmpl   $0x10,-0x10(%ebp)
 804a0b1:	7e 9c                	jle    804a04f <move_mouse+0xdc>
 804a0b3:	83 c4 24             	add    $0x24,%esp
 804a0b6:	5b                   	pop    %ebx
 804a0b7:	5d                   	pop    %ebp
 804a0b8:	c3                   	ret    

0804a0b9 <click_pos>:
 804a0b9:	55                   	push   %ebp
 804a0ba:	89 e5                	mov    %esp,%ebp
 804a0bc:	53                   	push   %ebx
 804a0bd:	83 ec 10             	sub    $0x10,%esp
 804a0c0:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a0c5:	89 45 f0             	mov    %eax,-0x10(%ebp)
 804a0c8:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a0cd:	89 45 ec             	mov    %eax,-0x14(%ebp)
 804a0d0:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a0d5:	8d 88 76 fd ff ff    	lea    -0x28a(%eax),%ecx
 804a0db:	ba 67 66 66 66       	mov    $0x66666667,%edx
 804a0e0:	89 c8                	mov    %ecx,%eax
 804a0e2:	f7 ea                	imul   %edx
 804a0e4:	c1 fa 04             	sar    $0x4,%edx
 804a0e7:	89 c8                	mov    %ecx,%eax
 804a0e9:	c1 f8 1f             	sar    $0x1f,%eax
 804a0ec:	89 d3                	mov    %edx,%ebx
 804a0ee:	29 c3                	sub    %eax,%ebx
 804a0f0:	89 d8                	mov    %ebx,%eax
 804a0f2:	89 45 f8             	mov    %eax,-0x8(%ebp)
 804a0f5:	8b 55 f8             	mov    -0x8(%ebp),%edx
 804a0f8:	89 d0                	mov    %edx,%eax
 804a0fa:	c1 e0 02             	shl    $0x2,%eax
 804a0fd:	01 d0                	add    %edx,%eax
 804a0ff:	c1 e0 03             	shl    $0x3,%eax
 804a102:	89 ca                	mov    %ecx,%edx
 804a104:	29 c2                	sub    %eax,%edx
 804a106:	89 d0                	mov    %edx,%eax
 804a108:	89 45 f8             	mov    %eax,-0x8(%ebp)
 804a10b:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a110:	8d 48 9c             	lea    -0x64(%eax),%ecx
 804a113:	ba 67 66 66 66       	mov    $0x66666667,%edx
 804a118:	89 c8                	mov    %ecx,%eax
 804a11a:	f7 ea                	imul   %edx
 804a11c:	c1 fa 04             	sar    $0x4,%edx
 804a11f:	89 c8                	mov    %ecx,%eax
 804a121:	c1 f8 1f             	sar    $0x1f,%eax
 804a124:	89 d3                	mov    %edx,%ebx
 804a126:	29 c3                	sub    %eax,%ebx
 804a128:	89 d8                	mov    %ebx,%eax
 804a12a:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804a12d:	8b 55 f4             	mov    -0xc(%ebp),%edx
 804a130:	89 d0                	mov    %edx,%eax
 804a132:	c1 e0 02             	shl    $0x2,%eax
 804a135:	01 d0                	add    %edx,%eax
 804a137:	c1 e0 03             	shl    $0x3,%eax
 804a13a:	89 ca                	mov    %ecx,%edx
 804a13c:	29 c2                	sub    %eax,%edx
 804a13e:	89 d0                	mov    %edx,%eax
 804a140:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804a143:	83 7d f8 14          	cmpl   $0x14,-0x8(%ebp)
 804a147:	7f 13                	jg     804a15c <click_pos+0xa3>
 804a149:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804a14c:	8b 55 f0             	mov    -0x10(%ebp),%edx
 804a14f:	89 d1                	mov    %edx,%ecx
 804a151:	29 c1                	sub    %eax,%ecx
 804a153:	89 c8                	mov    %ecx,%eax
 804a155:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 804a15a:	eb 14                	jmp    804a170 <click_pos+0xb7>
 804a15c:	8b 45 f8             	mov    -0x8(%ebp),%eax
 804a15f:	8b 55 f0             	mov    -0x10(%ebp),%edx
 804a162:	89 d3                	mov    %edx,%ebx
 804a164:	29 c3                	sub    %eax,%ebx
 804a166:	89 d8                	mov    %ebx,%eax
 804a168:	83 c0 28             	add    $0x28,%eax
 804a16b:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 804a170:	83 7d f4 14          	cmpl   $0x14,-0xc(%ebp)
 804a174:	7f 13                	jg     804a189 <click_pos+0xd0>
 804a176:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804a179:	8b 55 ec             	mov    -0x14(%ebp),%edx
 804a17c:	89 d1                	mov    %edx,%ecx
 804a17e:	29 c1                	sub    %eax,%ecx
 804a180:	89 c8                	mov    %ecx,%eax
 804a182:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 804a187:	eb 14                	jmp    804a19d <click_pos+0xe4>
 804a189:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804a18c:	8b 55 ec             	mov    -0x14(%ebp),%edx
 804a18f:	89 d3                	mov    %edx,%ebx
 804a191:	29 c3                	sub    %eax,%ebx
 804a193:	89 d8                	mov    %ebx,%eax
 804a195:	83 c0 28             	add    $0x28,%eax
 804a198:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 804a19d:	83 c4 10             	add    $0x10,%esp
 804a1a0:	5b                   	pop    %ebx
 804a1a1:	5d                   	pop    %ebp
 804a1a2:	c3                   	ret    
 804a1a3:	90                   	nop

0804a1a4 <player>:
 804a1a4:	55                   	push   %ebp
 804a1a5:	89 e5                	mov    %esp,%ebp
 804a1a7:	53                   	push   %ebx
 804a1a8:	81 ec 34 10 00 00    	sub    $0x1034,%esp
 804a1ae:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%ebp)
 804a1b5:	0f b6 05 04 c8 04 08 	movzbl 0x804c804,%eax
 804a1bc:	0f be c0             	movsbl %al,%eax
 804a1bf:	83 e0 01             	and    $0x1,%eax
 804a1c2:	84 c0                	test   %al,%al
 804a1c4:	0f 84 94 01 00 00    	je     804a35e <player+0x1ba>
 804a1ca:	c7 44 24 08 08 00 00 	movl   $0x8,0x8(%esp)
 804a1d1:	00 
 804a1d2:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
 804a1d9:	00 
 804a1da:	c7 04 24 04 c8 04 08 	movl   $0x804c804,(%esp)
 804a1e1:	e8 d6 e2 ff ff       	call   80484bc <memset@plt>
 804a1e6:	8b 45 08             	mov    0x8(%ebp),%eax
 804a1e9:	89 04 24             	mov    %eax,(%esp)
 804a1ec:	e8 82 fd ff ff       	call   8049f73 <move_mouse>
 804a1f1:	0f b6 05 04 c8 04 08 	movzbl 0x804c804,%eax
 804a1f8:	0f be c0             	movsbl %al,%eax
 804a1fb:	83 e0 01             	and    $0x1,%eax
 804a1fe:	85 c0                	test   %eax,%eax
 804a200:	0f 85 58 01 00 00    	jne    804a35e <player+0x1ba>
 804a206:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a20b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804a20e:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a213:	89 45 f0             	mov    %eax,-0x10(%ebp)
 804a216:	e8 9e fe ff ff       	call   804a0b9 <click_pos>
 804a21b:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a220:	3d 76 02 00 00       	cmp    $0x276,%eax
 804a225:	0f 8e 23 01 00 00    	jle    804a34e <player+0x1aa>
 804a22b:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a230:	83 f8 50             	cmp    $0x50,%eax
 804a233:	0f 8e 15 01 00 00    	jle    804a34e <player+0x1aa>
 804a239:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a23e:	3d c3 04 00 00       	cmp    $0x4c3,%eax
 804a243:	0f 8f 05 01 00 00    	jg     804a34e <player+0x1aa>
 804a249:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a24e:	3d 9d 02 00 00       	cmp    $0x29d,%eax
 804a253:	0f 8f f5 00 00 00    	jg     804a34e <player+0x1aa>
 804a259:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a25e:	8d 88 76 fd ff ff    	lea    -0x28a(%eax),%ecx
 804a264:	ba 67 66 66 66       	mov    $0x66666667,%edx
 804a269:	89 c8                	mov    %ecx,%eax
 804a26b:	f7 ea                	imul   %edx
 804a26d:	c1 fa 04             	sar    $0x4,%edx
 804a270:	89 c8                	mov    %ecx,%eax
 804a272:	c1 f8 1f             	sar    $0x1f,%eax
 804a275:	89 d1                	mov    %edx,%ecx
 804a277:	29 c1                	sub    %eax,%ecx
 804a279:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a27e:	8d 58 9c             	lea    -0x64(%eax),%ebx
 804a281:	ba 67 66 66 66       	mov    $0x66666667,%edx
 804a286:	89 d8                	mov    %ebx,%eax
 804a288:	f7 ea                	imul   %edx
 804a28a:	c1 fa 04             	sar    $0x4,%edx
 804a28d:	89 d8                	mov    %ebx,%eax
 804a28f:	c1 f8 1f             	sar    $0x1f,%eax
 804a292:	29 c2                	sub    %eax,%edx
 804a294:	89 c8                	mov    %ecx,%eax
 804a296:	c1 e0 04             	shl    $0x4,%eax
 804a299:	29 c8                	sub    %ecx,%eax
 804a29b:	01 d0                	add    %edx,%eax
 804a29d:	8b 04 85 80 c4 04 08 	mov    0x804c480(,%eax,4),%eax
 804a2a4:	85 c0                	test   %eax,%eax
 804a2a6:	0f 85 a2 00 00 00    	jne    804a34e <player+0x1aa>
 804a2ac:	8b 15 fc d6 04 08    	mov    0x804d6fc,%edx
 804a2b2:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a2b7:	89 54 24 04          	mov    %edx,0x4(%esp)
 804a2bb:	89 04 24             	mov    %eax,(%esp)
 804a2be:	e8 d7 e5 ff ff       	call   804889a <fb_white_point>
 804a2c3:	8b 1d fc d6 04 08    	mov    0x804d6fc,%ebx
 804a2c9:	8b 0d f4 d6 04 08    	mov    0x804d6f4,%ecx
 804a2cf:	a1 60 c0 04 08       	mov    0x804c060,%eax
 804a2d4:	89 c2                	mov    %eax,%edx
 804a2d6:	83 c0 01             	add    $0x1,%eax
 804a2d9:	a3 60 c0 04 08       	mov    %eax,0x804c060
 804a2de:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 804a2e5:	00 
 804a2e6:	89 5c 24 08          	mov    %ebx,0x8(%esp)
 804a2ea:	89 4c 24 04          	mov    %ecx,0x4(%esp)
 804a2ee:	89 14 24             	mov    %edx,(%esp)
 804a2f1:	e8 6a e7 ff ff       	call   8048a60 <fb_num>
 804a2f6:	a1 f4 d6 04 08       	mov    0x804d6f4,%eax
 804a2fb:	8d 88 76 fd ff ff    	lea    -0x28a(%eax),%ecx
 804a301:	ba 67 66 66 66       	mov    $0x66666667,%edx
 804a306:	89 c8                	mov    %ecx,%eax
 804a308:	f7 ea                	imul   %edx
 804a30a:	c1 fa 04             	sar    $0x4,%edx
 804a30d:	89 c8                	mov    %ecx,%eax
 804a30f:	c1 f8 1f             	sar    $0x1f,%eax
 804a312:	89 d1                	mov    %edx,%ecx
 804a314:	29 c1                	sub    %eax,%ecx
 804a316:	a1 fc d6 04 08       	mov    0x804d6fc,%eax
 804a31b:	8d 58 9c             	lea    -0x64(%eax),%ebx
 804a31e:	ba 67 66 66 66       	mov    $0x66666667,%edx
 804a323:	89 d8                	mov    %ebx,%eax
 804a325:	f7 ea                	imul   %edx
 804a327:	c1 fa 04             	sar    $0x4,%edx
 804a32a:	89 d8                	mov    %ebx,%eax
 804a32c:	c1 f8 1f             	sar    $0x1f,%eax
 804a32f:	29 c2                	sub    %eax,%edx
 804a331:	89 c8                	mov    %ecx,%eax
 804a333:	c1 e0 04             	shl    $0x4,%eax
 804a336:	29 c8                	sub    %ecx,%eax
 804a338:	01 d0                	add    %edx,%eax
 804a33a:	c7 04 85 80 c4 04 08 	movl   $0x1,0x804c480(,%eax,4)
 804a341:	01 00 00 00 
 804a345:	8b 45 0c             	mov    0xc(%ebp),%eax
 804a348:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
 804a34e:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804a351:	a3 f4 d6 04 08       	mov    %eax,0x804d6f4
 804a356:	8b 45 f0             	mov    -0x10(%ebp),%eax
 804a359:	a3 fc d6 04 08       	mov    %eax,0x804d6fc
 804a35e:	81 c4 34 10 00 00    	add    $0x1034,%esp
 804a364:	5b                   	pop    %ebx
 804a365:	5d                   	pop    %ebp
 804a366:	c3                   	ret    
 804a367:	90                   	nop
 804a368:	90                   	nop
 804a369:	90                   	nop
 804a36a:	90                   	nop
 804a36b:	90                   	nop
 804a36c:	90                   	nop
 804a36d:	90                   	nop
 804a36e:	90                   	nop
 804a36f:	90                   	nop

0804a370 <__libc_csu_fini>:
 804a370:	55                   	push   %ebp
 804a371:	89 e5                	mov    %esp,%ebp
 804a373:	5d                   	pop    %ebp
 804a374:	c3                   	ret    
 804a375:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 804a379:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

0804a380 <__libc_csu_init>:
 804a380:	55                   	push   %ebp
 804a381:	89 e5                	mov    %esp,%ebp
 804a383:	57                   	push   %edi
 804a384:	56                   	push   %esi
 804a385:	53                   	push   %ebx
 804a386:	e8 4f 00 00 00       	call   804a3da <__i686.get_pc_thunk.bx>
 804a38b:	81 c3 69 1c 00 00    	add    $0x1c69,%ebx
 804a391:	83 ec 1c             	sub    $0x1c,%esp
 804a394:	e8 b3 e0 ff ff       	call   804844c <_init>
 804a399:	8d bb 10 ff ff ff    	lea    -0xf0(%ebx),%edi
 804a39f:	8d 83 10 ff ff ff    	lea    -0xf0(%ebx),%eax
 804a3a5:	29 c7                	sub    %eax,%edi
 804a3a7:	c1 ff 02             	sar    $0x2,%edi
 804a3aa:	85 ff                	test   %edi,%edi
 804a3ac:	74 24                	je     804a3d2 <__libc_csu_init+0x52>
 804a3ae:	31 f6                	xor    %esi,%esi
 804a3b0:	8b 45 10             	mov    0x10(%ebp),%eax
 804a3b3:	89 44 24 08          	mov    %eax,0x8(%esp)
 804a3b7:	8b 45 0c             	mov    0xc(%ebp),%eax
 804a3ba:	89 44 24 04          	mov    %eax,0x4(%esp)
 804a3be:	8b 45 08             	mov    0x8(%ebp),%eax
 804a3c1:	89 04 24             	mov    %eax,(%esp)
 804a3c4:	ff 94 b3 10 ff ff ff 	call   *-0xf0(%ebx,%esi,4)
 804a3cb:	83 c6 01             	add    $0x1,%esi
 804a3ce:	39 fe                	cmp    %edi,%esi
 804a3d0:	72 de                	jb     804a3b0 <__libc_csu_init+0x30>
 804a3d2:	83 c4 1c             	add    $0x1c,%esp
 804a3d5:	5b                   	pop    %ebx
 804a3d6:	5e                   	pop    %esi
 804a3d7:	5f                   	pop    %edi
 804a3d8:	5d                   	pop    %ebp
 804a3d9:	c3                   	ret    

0804a3da <__i686.get_pc_thunk.bx>:
 804a3da:	8b 1c 24             	mov    (%esp),%ebx
 804a3dd:	c3                   	ret    
 804a3de:	90                   	nop
 804a3df:	90                   	nop

0804a3e0 <__do_global_ctors_aux>:
 804a3e0:	55                   	push   %ebp
 804a3e1:	89 e5                	mov    %esp,%ebp
 804a3e3:	53                   	push   %ebx
 804a3e4:	83 ec 04             	sub    $0x4,%esp
 804a3e7:	a1 04 bf 04 08       	mov    0x804bf04,%eax
 804a3ec:	83 f8 ff             	cmp    $0xffffffff,%eax
 804a3ef:	74 13                	je     804a404 <__do_global_ctors_aux+0x24>
 804a3f1:	bb 04 bf 04 08       	mov    $0x804bf04,%ebx
 804a3f6:	66 90                	xchg   %ax,%ax
 804a3f8:	83 eb 04             	sub    $0x4,%ebx
 804a3fb:	ff d0                	call   *%eax
 804a3fd:	8b 03                	mov    (%ebx),%eax
 804a3ff:	83 f8 ff             	cmp    $0xffffffff,%eax
 804a402:	75 f4                	jne    804a3f8 <__do_global_ctors_aux+0x18>
 804a404:	83 c4 04             	add    $0x4,%esp
 804a407:	5b                   	pop    %ebx
 804a408:	5d                   	pop    %ebp
 804a409:	c3                   	ret    
 804a40a:	90                   	nop
 804a40b:	90                   	nop

Disassembly of section .fini:

0804a40c <_fini>:
 804a40c:	55                   	push   %ebp
 804a40d:	89 e5                	mov    %esp,%ebp
 804a40f:	53                   	push   %ebx
 804a410:	83 ec 04             	sub    $0x4,%esp
 804a413:	e8 00 00 00 00       	call   804a418 <_fini+0xc>
 804a418:	5b                   	pop    %ebx
 804a419:	81 c3 dc 1b 00 00    	add    $0x1bdc,%ebx
 804a41f:	e8 5c e1 ff ff       	call   8048580 <__do_global_dtors_aux>
 804a424:	59                   	pop    %ecx
 804a425:	5b                   	pop    %ebx
 804a426:	c9                   	leave  
 804a427:	c3                   	ret    

Disassembly of section .rodata:

0804a428 <_fp_hw>:
 804a428:	03 00                	add    (%eax),%eax
	...

0804a42c <_IO_stdin_used>:
 804a42c:	01 00                	add    %eax,(%eax)
 804a42e:	02 00                	add    (%eax),%al
 804a430:	70 6c                	jo     804a49e <_IO_stdin_used+0x72>
 804a432:	61                   	popa   
 804a433:	79 65                	jns    804a49a <_IO_stdin_used+0x6e>
 804a435:	72 5f                	jb     804a496 <_IO_stdin_used+0x6a>
 804a437:	6d                   	insl   (%dx),%es:(%edi)
 804a438:	61                   	popa   
 804a439:	78 3a                	js     804a475 <_IO_stdin_used+0x49>
 804a43b:	28 25 64 2c 20 25    	sub    %ah,0x25202c64
 804a441:	64 29 0a             	sub    %ecx,%fs:(%edx)
 804a444:	00 63 6f             	add    %ah,0x6f(%ebx)
 804a447:	6d                   	insl   (%dx),%es:(%edi)
 804a448:	70 75                	jo     804a4bf <_IO_stdin_used+0x93>
 804a44a:	74 65                	je     804a4b1 <_IO_stdin_used+0x85>
 804a44c:	72 5f                	jb     804a4ad <_IO_stdin_used+0x81>
 804a44e:	6d                   	insl   (%dx),%es:(%edi)
 804a44f:	61                   	popa   
 804a450:	78 3a                	js     804a48c <_IO_stdin_used+0x60>
 804a452:	28 25 64 2c 20 25    	sub    %ah,0x25202c64
 804a458:	64 29 0a             	sub    %ecx,%fs:(%edx)
 804a45b:	00 00                	add    %al,(%eax)
 804a45d:	00 00                	add    %al,(%eax)
 804a45f:	00 55 09             	add    %dl,0x9(%ebp)
 804a462:	8b d9                	mov    %ecx,%ebx
 804a464:	f4                   	hlt    
 804a465:	dc 91 3f 1f 85 eb    	fcoml  -0x147ae0c1(%ecx)
 804a46b:	51                   	push   %ecx
 804a46c:	b8 1e 19 40 77       	mov    $0x7740191e,%eax
 804a471:	68 69 74 65 20       	push   $0x20657469
 804a476:	77 69                	ja     804a4e1 <_IO_stdin_used+0xb5>
 804a478:	6e                   	outsb  %ds:(%esi),(%dx)
 804a479:	21 00                	and    %eax,(%eax)
 804a47b:	62 6c 61 63          	bound  %ebp,0x63(%ecx,%eiz,2)
 804a47f:	6b 20 77             	imul   $0x77,(%eax),%esp
 804a482:	69 6e 21 00 2f 64 65 	imul   $0x65642f00,0x21(%esi),%ebp
 804a489:	76 2f                	jbe    804a4ba <_IO_stdin_used+0x8e>
 804a48b:	66 62 30             	bound  %si,(%eax)
 804a48e:	00 6f 70             	add    %ch,0x70(%edi)
 804a491:	65 6e                	outsb  %gs:(%esi),(%dx)
 804a493:	20 66 62             	and    %ah,0x62(%esi)
 804a496:	30 20                	xor    %ah,(%eax)
 804a498:	65                   	gs
 804a499:	72 72                	jb     804a50d <__FRAME_END__+0x21>
 804a49b:	6f                   	outsl  %ds:(%esi),(%dx)
 804a49c:	72 21                	jb     804a4bf <_IO_stdin_used+0x93>
 804a49e:	00 46 72             	add    %al,0x72(%esi)
 804a4a1:	61                   	popa   
 804a4a2:	6d                   	insl   (%dx),%es:(%edi)
 804a4a3:	65 62 75 66          	bound  %esi,%gs:0x66(%ebp)
 804a4a7:	66                   	data16
 804a4a8:	65                   	gs
 804a4a9:	72 3a                	jb     804a4e5 <_IO_stdin_used+0xb9>
 804a4ab:	25 64 20 2a 20       	and    $0x202a2064,%eax
 804a4b0:	25 64 0a 00 42       	and    $0x42000a64,%eax
 804a4b5:	69 74 73 3a 25 64 0a 	imul   $0xa6425,0x3a(%ebx,%esi,2),%esi
 804a4bc:	00 
 804a4bd:	2f                   	das    
 804a4be:	64                   	fs
 804a4bf:	65                   	gs
 804a4c0:	76 2f                	jbe    804a4f1 <__FRAME_END__+0x5>
 804a4c2:	69 6e 70 75 74 2f 6d 	imul   $0x6d2f7475,0x70(%esi),%ebp
 804a4c9:	69 63 65 00 6f 70 65 	imul   $0x65706f00,0x65(%ebx),%esp
 804a4d0:	6e                   	outsb  %ds:(%esi),(%dx)
 804a4d1:	20 2f                	and    %ch,(%edi)
 804a4d3:	64                   	fs
 804a4d4:	65                   	gs
 804a4d5:	76 2f                	jbe    804a506 <__FRAME_END__+0x1a>
 804a4d7:	69 6e 70 75 74 2f 6d 	imul   $0x6d2f7475,0x70(%esi),%ebp
 804a4de:	69 63 65 20 65 72 72 	imul   $0x72726520,0x65(%ebx),%esp
 804a4e5:	6f                   	outsl  %ds:(%esi),(%dx)
 804a4e6:	72 21                	jb     804a509 <__FRAME_END__+0x1d>
	...

Disassembly of section .eh_frame:

0804a4ec <__FRAME_END__>:
 804a4ec:	00 00                	add    %al,(%eax)
	...

Disassembly of section .ctors:

0804bf04 <__CTOR_LIST__>:
 804bf04:	ff                   	(bad)  
 804bf05:	ff                   	(bad)  
 804bf06:	ff                   	(bad)  
 804bf07:	ff 00                	incl   (%eax)

0804bf08 <__CTOR_END__>:
 804bf08:	00 00                	add    %al,(%eax)
	...

Disassembly of section .dtors:

0804bf0c <__DTOR_LIST__>:
 804bf0c:	ff                   	(bad)  
 804bf0d:	ff                   	(bad)  
 804bf0e:	ff                   	(bad)  
 804bf0f:	ff 00                	incl   (%eax)

0804bf10 <__DTOR_END__>:
 804bf10:	00 00                	add    %al,(%eax)
	...

Disassembly of section .jcr:

0804bf14 <__JCR_END__>:
 804bf14:	00 00                	add    %al,(%eax)
	...

Disassembly of section .dynamic:

0804bf18 <_DYNAMIC>:
 804bf18:	01 00                	add    %eax,(%eax)
 804bf1a:	00 00                	add    %al,(%eax)
 804bf1c:	01 00                	add    %eax,(%eax)
 804bf1e:	00 00                	add    %al,(%eax)
 804bf20:	01 00                	add    %eax,(%eax)
 804bf22:	00 00                	add    %al,(%eax)
 804bf24:	36 00 00             	add    %al,%ss:(%eax)
 804bf27:	00 0c 00             	add    %cl,(%eax,%eax,1)
 804bf2a:	00 00                	add    %al,(%eax)
 804bf2c:	4c                   	dec    %esp
 804bf2d:	84 04 08             	test   %al,(%eax,%ecx,1)
 804bf30:	0d 00 00 00 0c       	or     $0xc000000,%eax
 804bf35:	a4                   	movsb  %ds:(%esi),%es:(%edi)
 804bf36:	04 08                	add    $0x8,%al
 804bf38:	04 00                	add    $0x0,%al
 804bf3a:	00 00                	add    %al,(%eax)
 804bf3c:	8c 81 04 08 f5 fe    	mov    %es,-0x10af7fc(%ecx)
 804bf42:	ff 6f dc             	ljmp   *-0x24(%edi)
 804bf45:	81 04 08 05 00 00 00 	addl   $0x5,(%eax,%ecx,1)
 804bf4c:	ec                   	in     (%dx),%al
 804bf4d:	82                   	(bad)  
 804bf4e:	04 08                	add    $0x8,%al
 804bf50:	06                   	push   %es
 804bf51:	00 00                	add    %al,(%eax)
 804bf53:	00 fc                	add    %bh,%ah
 804bf55:	81 04 08 0a 00 00 00 	addl   $0xa,(%eax,%ecx,1)
 804bf5c:	98                   	cwtl   
 804bf5d:	00 00                	add    %al,(%eax)
 804bf5f:	00 0b                	add    %cl,(%ebx)
 804bf61:	00 00                	add    %al,(%eax)
 804bf63:	00 10                	add    %dl,(%eax)
 804bf65:	00 00                	add    %al,(%eax)
 804bf67:	00 15 00 00 00 00    	add    %dl,0x0
 804bf6d:	00 00                	add    %al,(%eax)
 804bf6f:	00 03                	add    %al,(%ebx)
 804bf71:	00 00                	add    %al,(%eax)
 804bf73:	00 f4                	add    %dh,%ah
 804bf75:	bf 04 08 02 00       	mov    $0x20804,%edi
 804bf7a:	00 00                	add    %al,(%eax)
 804bf7c:	60                   	pusha  
 804bf7d:	00 00                	add    %al,(%eax)
 804bf7f:	00 14 00             	add    %dl,(%eax,%eax,1)
 804bf82:	00 00                	add    %al,(%eax)
 804bf84:	11 00                	adc    %eax,(%eax)
 804bf86:	00 00                	add    %al,(%eax)
 804bf88:	17                   	pop    %ss
 804bf89:	00 00                	add    %al,(%eax)
 804bf8b:	00 ec                	add    %ch,%ah
 804bf8d:	83 04 08 11          	addl   $0x11,(%eax,%ecx,1)
 804bf91:	00 00                	add    %al,(%eax)
 804bf93:	00 e4                	add    %ah,%ah
 804bf95:	83 04 08 12          	addl   $0x12,(%eax,%ecx,1)
 804bf99:	00 00                	add    %al,(%eax)
 804bf9b:	00 08                	add    %cl,(%eax)
 804bf9d:	00 00                	add    %al,(%eax)
 804bf9f:	00 13                	add    %dl,(%ebx)
 804bfa1:	00 00                	add    %al,(%eax)
 804bfa3:	00 08                	add    %cl,(%eax)
 804bfa5:	00 00                	add    %al,(%eax)
 804bfa7:	00 fe                	add    %bh,%dh
 804bfa9:	ff                   	(bad)  
 804bfaa:	ff 6f a4             	ljmp   *-0x5c(%edi)
 804bfad:	83 04 08 ff          	addl   $0xffffffff,(%eax,%ecx,1)
 804bfb1:	ff                   	(bad)  
 804bfb2:	ff 6f 02             	ljmp   *0x2(%edi)
 804bfb5:	00 00                	add    %al,(%eax)
 804bfb7:	00 f0                	add    %dh,%al
 804bfb9:	ff                   	(bad)  
 804bfba:	ff 6f 84             	ljmp   *-0x7c(%edi)
 804bfbd:	83 04 08 00          	addl   $0x0,(%eax,%ecx,1)
	...

Disassembly of section .got:

0804bff0 <.got>:
 804bff0:	00 00                	add    %al,(%eax)
	...

Disassembly of section .got.plt:

0804bff4 <_GLOBAL_OFFSET_TABLE_>:
 804bff4:	18 bf 04 08 00 00    	sbb    %bh,0x804(%edi)
 804bffa:	00 00                	add    %al,(%eax)
 804bffc:	00 00                	add    %al,(%eax)
 804bffe:	00 00                	add    %al,(%eax)
 804c000:	92                   	xchg   %eax,%edx
 804c001:	84 04 08             	test   %al,(%eax,%ecx,1)
 804c004:	a2 84 04 08 b2       	mov    %al,0xb2080484
 804c009:	84 04 08             	test   %al,(%eax,%ecx,1)
 804c00c:	c2 84 04             	ret    $0x484
 804c00f:	08 d2                	or     %dl,%dl
 804c011:	84 04 08             	test   %al,(%eax,%ecx,1)
 804c014:	e2 84                	loop   804bf9a <_DYNAMIC+0x82>
 804c016:	04 08                	add    $0x8,%al
 804c018:	f2 84 04 08          	repnz test %al,(%eax,%ecx,1)
 804c01c:	02 85 04 08 12 85    	add    -0x7aedf7fc(%ebp),%al
 804c022:	04 08                	add    $0x8,%al
 804c024:	22 85 04 08 32 85    	and    -0x7acdf7fc(%ebp),%al
 804c02a:	04 08                	add    $0x8,%al
 804c02c:	42                   	inc    %edx
 804c02d:	85 04 08             	test   %eax,(%eax,%ecx,1)

Disassembly of section .data:

0804c040 <__data_start>:
 804c040:	00 00                	add    %al,(%eax)
	...

0804c044 <__dso_handle>:
	...

0804c060 <chess_num>:
 804c060:	01 00                	add    %eax,(%eax)
	...

0804c080 <F>:
 804c080:	00 00                	add    %al,(%eax)
 804c082:	00 00                	add    %al,(%eax)
 804c084:	02 00                	add    (%eax),%al
 804c086:	00 00                	add    %al,(%eax)
 804c088:	05 00 00 00 32       	add    $0x32000000,%eax
 804c08d:	00 00                	add    %al,(%eax)
 804c08f:	00 80 3e 00 00 00    	add    %al,0x3e(%eax)
 804c095:	00 00                	add    %al,(%eax)
 804c097:	00 0a                	add    %cl,(%edx)
 804c099:	00 00                	add    %al,(%eax)
 804c09b:	00 1e                	add    %bl,(%esi)
 804c09d:	00 00                	add    %al,(%eax)
 804c09f:	00 ee                	add    %ch,%dh
 804c0a1:	02 00                	add    (%eax),%al
 804c0a3:	00 80 3e 00 00 00    	add    %al,0x3e(%eax)
	...

0804c0c0 <L>:
 804c0c0:	00 00                	add    %al,(%eax)
 804c0c2:	00 00                	add    %al,(%eax)
 804c0c4:	01 00                	add    %eax,(%eax)
 804c0c6:	00 00                	add    %al,(%eax)
 804c0c8:	05 00 00 00 32       	add    $0x32000000,%eax
 804c0cd:	00 00                	add    %al,(%eax)
 804c0cf:	00 a6 0e 00 00 00    	add    %ah,0xe(%esi)
 804c0d5:	00 00                	add    %al,(%eax)
 804c0d7:	00 0a                	add    %cl,(%edx)
 804c0d9:	00 00                	add    %al,(%eax)
 804c0db:	00 1e                	add    %bl,(%esi)
 804c0dd:	00 00                	add    %al,(%eax)
 804c0df:	00 96 00 00 00 a0    	add    %dl,-0x60000000(%esi)
 804c0e5:	0f 00 00             	sldt   (%eax)
	...

0804c100 <cursor_pixel>:
 804c100:	00 00                	add    %al,(%eax)
 804c102:	00 00                	add    %al,(%eax)
 804c104:	00 00                	add    %al,(%eax)
 804c106:	ff 00                	incl   (%eax)
 804c108:	00 00                	add    %al,(%eax)
 804c10a:	ff 00                	incl   (%eax)
 804c10c:	00 00                	add    %al,(%eax)
 804c10e:	ff 00                	incl   (%eax)
 804c110:	00 00                	add    %al,(%eax)
 804c112:	ff 00                	incl   (%eax)
 804c114:	00 00                	add    %al,(%eax)
 804c116:	ff 00                	incl   (%eax)
 804c118:	00 00                	add    %al,(%eax)
 804c11a:	ff 00                	incl   (%eax)
 804c11c:	00 00                	add    %al,(%eax)
 804c11e:	ff 00                	incl   (%eax)
 804c120:	00 00                	add    %al,(%eax)
 804c122:	ff 00                	incl   (%eax)
 804c124:	00 00                	add    %al,(%eax)
 804c126:	ff 00                	incl   (%eax)
	...
 804c130:	00 00                	add    %al,(%eax)
 804c132:	ff 00                	incl   (%eax)
 804c134:	00 00                	add    %al,(%eax)
 804c136:	ff 00                	incl   (%eax)
 804c138:	00 00                	add    %al,(%eax)
 804c13a:	ff 00                	incl   (%eax)
 804c13c:	00 00                	add    %al,(%eax)
 804c13e:	ff 00                	incl   (%eax)
 804c140:	00 00                	add    %al,(%eax)
 804c142:	ff 00                	incl   (%eax)
 804c144:	00 00                	add    %al,(%eax)
 804c146:	ff 00                	incl   (%eax)
 804c148:	00 00                	add    %al,(%eax)
 804c14a:	ff 00                	incl   (%eax)
 804c14c:	00 00                	add    %al,(%eax)
 804c14e:	ff 00                	incl   (%eax)
 804c150:	00 00                	add    %al,(%eax)
 804c152:	00 00                	add    %al,(%eax)
 804c154:	ff                   	(bad)  
 804c155:	ff                   	(bad)  
 804c156:	ff 00                	incl   (%eax)
 804c158:	00 00                	add    %al,(%eax)
 804c15a:	00 00                	add    %al,(%eax)
 804c15c:	00 00                	add    %al,(%eax)
 804c15e:	ff 00                	incl   (%eax)
 804c160:	00 00                	add    %al,(%eax)
 804c162:	ff 00                	incl   (%eax)
 804c164:	00 00                	add    %al,(%eax)
 804c166:	ff 00                	incl   (%eax)
 804c168:	00 00                	add    %al,(%eax)
 804c16a:	ff 00                	incl   (%eax)
 804c16c:	00 00                	add    %al,(%eax)
 804c16e:	ff 00                	incl   (%eax)
 804c170:	00 00                	add    %al,(%eax)
 804c172:	ff 00                	incl   (%eax)
 804c174:	00 00                	add    %al,(%eax)
 804c176:	ff 00                	incl   (%eax)
 804c178:	00 00                	add    %al,(%eax)
 804c17a:	00 00                	add    %al,(%eax)
 804c17c:	ff                   	(bad)  
 804c17d:	ff                   	(bad)  
 804c17e:	ff 00                	incl   (%eax)
 804c180:	ff                   	(bad)  
 804c181:	ff                   	(bad)  
 804c182:	ff 00                	incl   (%eax)
 804c184:	00 00                	add    %al,(%eax)
 804c186:	00 00                	add    %al,(%eax)
 804c188:	00 00                	add    %al,(%eax)
 804c18a:	ff 00                	incl   (%eax)
 804c18c:	00 00                	add    %al,(%eax)
 804c18e:	ff 00                	incl   (%eax)
 804c190:	00 00                	add    %al,(%eax)
 804c192:	ff 00                	incl   (%eax)
 804c194:	00 00                	add    %al,(%eax)
 804c196:	ff 00                	incl   (%eax)
 804c198:	00 00                	add    %al,(%eax)
 804c19a:	ff 00                	incl   (%eax)
 804c19c:	00 00                	add    %al,(%eax)
 804c19e:	ff 00                	incl   (%eax)
 804c1a0:	00 00                	add    %al,(%eax)
 804c1a2:	00 00                	add    %al,(%eax)
 804c1a4:	ff                   	(bad)  
 804c1a5:	ff                   	(bad)  
 804c1a6:	ff 00                	incl   (%eax)
 804c1a8:	ff                   	(bad)  
 804c1a9:	ff                   	(bad)  
 804c1aa:	ff 00                	incl   (%eax)
 804c1ac:	ff                   	(bad)  
 804c1ad:	ff                   	(bad)  
 804c1ae:	ff 00                	incl   (%eax)
 804c1b0:	00 00                	add    %al,(%eax)
 804c1b2:	00 00                	add    %al,(%eax)
 804c1b4:	00 00                	add    %al,(%eax)
 804c1b6:	ff 00                	incl   (%eax)
 804c1b8:	00 00                	add    %al,(%eax)
 804c1ba:	ff 00                	incl   (%eax)
 804c1bc:	00 00                	add    %al,(%eax)
 804c1be:	ff 00                	incl   (%eax)
 804c1c0:	00 00                	add    %al,(%eax)
 804c1c2:	ff 00                	incl   (%eax)
 804c1c4:	00 00                	add    %al,(%eax)
 804c1c6:	ff 00                	incl   (%eax)
 804c1c8:	00 00                	add    %al,(%eax)
 804c1ca:	00 00                	add    %al,(%eax)
 804c1cc:	ff                   	(bad)  
 804c1cd:	ff                   	(bad)  
 804c1ce:	ff 00                	incl   (%eax)
 804c1d0:	ff                   	(bad)  
 804c1d1:	ff                   	(bad)  
 804c1d2:	ff 00                	incl   (%eax)
 804c1d4:	ff                   	(bad)  
 804c1d5:	ff                   	(bad)  
 804c1d6:	ff 00                	incl   (%eax)
 804c1d8:	ff                   	(bad)  
 804c1d9:	ff                   	(bad)  
 804c1da:	ff 00                	incl   (%eax)
 804c1dc:	00 00                	add    %al,(%eax)
 804c1de:	00 00                	add    %al,(%eax)
 804c1e0:	00 00                	add    %al,(%eax)
 804c1e2:	ff 00                	incl   (%eax)
 804c1e4:	00 00                	add    %al,(%eax)
 804c1e6:	ff 00                	incl   (%eax)
 804c1e8:	00 00                	add    %al,(%eax)
 804c1ea:	ff 00                	incl   (%eax)
 804c1ec:	00 00                	add    %al,(%eax)
 804c1ee:	ff 00                	incl   (%eax)
 804c1f0:	00 00                	add    %al,(%eax)
 804c1f2:	00 00                	add    %al,(%eax)
 804c1f4:	ff                   	(bad)  
 804c1f5:	ff                   	(bad)  
 804c1f6:	ff 00                	incl   (%eax)
 804c1f8:	ff                   	(bad)  
 804c1f9:	ff                   	(bad)  
 804c1fa:	ff 00                	incl   (%eax)
 804c1fc:	ff                   	(bad)  
 804c1fd:	ff                   	(bad)  
 804c1fe:	ff 00                	incl   (%eax)
 804c200:	ff                   	(bad)  
 804c201:	ff                   	(bad)  
 804c202:	ff 00                	incl   (%eax)
 804c204:	ff                   	(bad)  
 804c205:	ff                   	(bad)  
 804c206:	ff 00                	incl   (%eax)
 804c208:	00 00                	add    %al,(%eax)
 804c20a:	00 00                	add    %al,(%eax)
 804c20c:	00 00                	add    %al,(%eax)
 804c20e:	ff 00                	incl   (%eax)
 804c210:	00 00                	add    %al,(%eax)
 804c212:	ff 00                	incl   (%eax)
 804c214:	00 00                	add    %al,(%eax)
 804c216:	ff 00                	incl   (%eax)
 804c218:	00 00                	add    %al,(%eax)
 804c21a:	00 00                	add    %al,(%eax)
 804c21c:	ff                   	(bad)  
 804c21d:	ff                   	(bad)  
 804c21e:	ff 00                	incl   (%eax)
 804c220:	ff                   	(bad)  
 804c221:	ff                   	(bad)  
 804c222:	ff 00                	incl   (%eax)
 804c224:	ff                   	(bad)  
 804c225:	ff                   	(bad)  
 804c226:	ff 00                	incl   (%eax)
 804c228:	ff                   	(bad)  
 804c229:	ff                   	(bad)  
 804c22a:	ff 00                	incl   (%eax)
 804c22c:	ff                   	(bad)  
 804c22d:	ff                   	(bad)  
 804c22e:	ff 00                	incl   (%eax)
 804c230:	ff                   	(bad)  
 804c231:	ff                   	(bad)  
 804c232:	ff 00                	incl   (%eax)
 804c234:	00 00                	add    %al,(%eax)
 804c236:	00 00                	add    %al,(%eax)
 804c238:	00 00                	add    %al,(%eax)
 804c23a:	ff 00                	incl   (%eax)
 804c23c:	00 00                	add    %al,(%eax)
 804c23e:	ff 00                	incl   (%eax)
 804c240:	00 00                	add    %al,(%eax)
 804c242:	00 00                	add    %al,(%eax)
 804c244:	ff                   	(bad)  
 804c245:	ff                   	(bad)  
 804c246:	ff 00                	incl   (%eax)
 804c248:	ff                   	(bad)  
 804c249:	ff                   	(bad)  
 804c24a:	ff 00                	incl   (%eax)
 804c24c:	ff                   	(bad)  
 804c24d:	ff                   	(bad)  
 804c24e:	ff 00                	incl   (%eax)
 804c250:	ff                   	(bad)  
 804c251:	ff                   	(bad)  
 804c252:	ff 00                	incl   (%eax)
 804c254:	ff                   	(bad)  
 804c255:	ff                   	(bad)  
 804c256:	ff 00                	incl   (%eax)
 804c258:	ff                   	(bad)  
 804c259:	ff                   	(bad)  
 804c25a:	ff 00                	incl   (%eax)
 804c25c:	ff                   	(bad)  
 804c25d:	ff                   	(bad)  
 804c25e:	ff 00                	incl   (%eax)
 804c260:	00 00                	add    %al,(%eax)
 804c262:	00 00                	add    %al,(%eax)
 804c264:	00 00                	add    %al,(%eax)
 804c266:	ff 00                	incl   (%eax)
 804c268:	00 00                	add    %al,(%eax)
 804c26a:	00 00                	add    %al,(%eax)
 804c26c:	ff                   	(bad)  
 804c26d:	ff                   	(bad)  
 804c26e:	ff 00                	incl   (%eax)
 804c270:	ff                   	(bad)  
 804c271:	ff                   	(bad)  
 804c272:	ff 00                	incl   (%eax)
 804c274:	ff                   	(bad)  
 804c275:	ff                   	(bad)  
 804c276:	ff 00                	incl   (%eax)
 804c278:	ff                   	(bad)  
 804c279:	ff                   	(bad)  
 804c27a:	ff 00                	incl   (%eax)
 804c27c:	ff                   	(bad)  
 804c27d:	ff                   	(bad)  
 804c27e:	ff 00                	incl   (%eax)
 804c280:	ff                   	(bad)  
 804c281:	ff                   	(bad)  
 804c282:	ff 00                	incl   (%eax)
 804c284:	ff                   	(bad)  
 804c285:	ff                   	(bad)  
 804c286:	ff 00                	incl   (%eax)
 804c288:	ff                   	(bad)  
 804c289:	ff                   	(bad)  
 804c28a:	ff 00                	incl   (%eax)
	...
 804c294:	ff                   	(bad)  
 804c295:	ff                   	(bad)  
 804c296:	ff 00                	incl   (%eax)
 804c298:	ff                   	(bad)  
 804c299:	ff                   	(bad)  
 804c29a:	ff 00                	incl   (%eax)
 804c29c:	ff                   	(bad)  
 804c29d:	ff                   	(bad)  
 804c29e:	ff 00                	incl   (%eax)
 804c2a0:	ff                   	(bad)  
 804c2a1:	ff                   	(bad)  
 804c2a2:	ff 00                	incl   (%eax)
 804c2a4:	ff                   	(bad)  
 804c2a5:	ff                   	(bad)  
 804c2a6:	ff 00                	incl   (%eax)
	...
 804c2bc:	ff                   	(bad)  
 804c2bd:	ff                   	(bad)  
 804c2be:	ff 00                	incl   (%eax)
 804c2c0:	ff                   	(bad)  
 804c2c1:	ff                   	(bad)  
 804c2c2:	ff 00                	incl   (%eax)
 804c2c4:	00 00                	add    %al,(%eax)
 804c2c6:	00 00                	add    %al,(%eax)
 804c2c8:	ff                   	(bad)  
 804c2c9:	ff                   	(bad)  
 804c2ca:	ff 00                	incl   (%eax)
 804c2cc:	ff                   	(bad)  
 804c2cd:	ff                   	(bad)  
 804c2ce:	ff 00                	incl   (%eax)
 804c2d0:	00 00                	add    %al,(%eax)
 804c2d2:	00 00                	add    %al,(%eax)
 804c2d4:	00 00                	add    %al,(%eax)
 804c2d6:	ff 00                	incl   (%eax)
 804c2d8:	00 00                	add    %al,(%eax)
 804c2da:	ff 00                	incl   (%eax)
 804c2dc:	00 00                	add    %al,(%eax)
 804c2de:	ff 00                	incl   (%eax)
 804c2e0:	00 00                	add    %al,(%eax)
 804c2e2:	00 00                	add    %al,(%eax)
 804c2e4:	ff                   	(bad)  
 804c2e5:	ff                   	(bad)  
 804c2e6:	ff 00                	incl   (%eax)
 804c2e8:	00 00                	add    %al,(%eax)
 804c2ea:	00 00                	add    %al,(%eax)
 804c2ec:	00 00                	add    %al,(%eax)
 804c2ee:	ff 00                	incl   (%eax)
 804c2f0:	00 00                	add    %al,(%eax)
 804c2f2:	00 00                	add    %al,(%eax)
 804c2f4:	ff                   	(bad)  
 804c2f5:	ff                   	(bad)  
 804c2f6:	ff 00                	incl   (%eax)
 804c2f8:	ff                   	(bad)  
 804c2f9:	ff                   	(bad)  
 804c2fa:	ff 00                	incl   (%eax)
 804c2fc:	00 00                	add    %al,(%eax)
 804c2fe:	00 00                	add    %al,(%eax)
 804c300:	00 00                	add    %al,(%eax)
 804c302:	ff 00                	incl   (%eax)
 804c304:	00 00                	add    %al,(%eax)
 804c306:	ff 00                	incl   (%eax)
	...
 804c310:	00 00                	add    %al,(%eax)
 804c312:	ff 00                	incl   (%eax)
 804c314:	00 00                	add    %al,(%eax)
 804c316:	ff 00                	incl   (%eax)
 804c318:	00 00                	add    %al,(%eax)
 804c31a:	00 00                	add    %al,(%eax)
 804c31c:	ff                   	(bad)  
 804c31d:	ff                   	(bad)  
 804c31e:	ff 00                	incl   (%eax)
 804c320:	ff                   	(bad)  
 804c321:	ff                   	(bad)  
 804c322:	ff 00                	incl   (%eax)
 804c324:	00 00                	add    %al,(%eax)
 804c326:	00 00                	add    %al,(%eax)
 804c328:	00 00                	add    %al,(%eax)
 804c32a:	ff 00                	incl   (%eax)
 804c32c:	00 00                	add    %al,(%eax)
 804c32e:	ff 00                	incl   (%eax)
 804c330:	00 00                	add    %al,(%eax)
 804c332:	ff 00                	incl   (%eax)
 804c334:	00 00                	add    %al,(%eax)
 804c336:	ff 00                	incl   (%eax)
 804c338:	00 00                	add    %al,(%eax)
 804c33a:	ff 00                	incl   (%eax)
 804c33c:	00 00                	add    %al,(%eax)
 804c33e:	ff 00                	incl   (%eax)
 804c340:	00 00                	add    %al,(%eax)
 804c342:	ff 00                	incl   (%eax)
 804c344:	00 00                	add    %al,(%eax)
 804c346:	00 00                	add    %al,(%eax)
 804c348:	ff                   	(bad)  
 804c349:	ff                   	(bad)  
 804c34a:	ff 00                	incl   (%eax)
 804c34c:	ff                   	(bad)  
 804c34d:	ff                   	(bad)  
 804c34e:	ff 00                	incl   (%eax)
 804c350:	00 00                	add    %al,(%eax)
 804c352:	00 00                	add    %al,(%eax)
 804c354:	00 00                	add    %al,(%eax)
 804c356:	ff 00                	incl   (%eax)
 804c358:	00 00                	add    %al,(%eax)
 804c35a:	ff 00                	incl   (%eax)
 804c35c:	00 00                	add    %al,(%eax)
 804c35e:	ff 00                	incl   (%eax)
 804c360:	00 00                	add    %al,(%eax)
 804c362:	ff 00                	incl   (%eax)
 804c364:	00 00                	add    %al,(%eax)
 804c366:	ff 00                	incl   (%eax)
 804c368:	00 00                	add    %al,(%eax)
 804c36a:	ff 00                	incl   (%eax)
 804c36c:	00 00                	add    %al,(%eax)
 804c36e:	00 00                	add    %al,(%eax)
 804c370:	ff                   	(bad)  
 804c371:	ff                   	(bad)  
 804c372:	ff 00                	incl   (%eax)
 804c374:	ff                   	(bad)  
 804c375:	ff                   	(bad)  
 804c376:	ff 00                	incl   (%eax)
 804c378:	00 00                	add    %al,(%eax)
 804c37a:	00 00                	add    %al,(%eax)
 804c37c:	00 00                	add    %al,(%eax)
 804c37e:	ff 00                	incl   (%eax)
 804c380:	00 00                	add    %al,(%eax)
 804c382:	ff 00                	incl   (%eax)
 804c384:	00 00                	add    %al,(%eax)
 804c386:	ff 00                	incl   (%eax)
 804c388:	00 00                	add    %al,(%eax)
 804c38a:	ff 00                	incl   (%eax)
 804c38c:	00 00                	add    %al,(%eax)
 804c38e:	ff 00                	incl   (%eax)
 804c390:	00 00                	add    %al,(%eax)
 804c392:	ff 00                	incl   (%eax)
 804c394:	00 00                	add    %al,(%eax)
 804c396:	ff 00                	incl   (%eax)
	...
 804c3a0:	00 00                	add    %al,(%eax)
 804c3a2:	ff 00                	incl   (%eax)
 804c3a4:	00 00                	add    %al,(%eax)
 804c3a6:	ff 00                	incl   (%eax)
	...

0804c3c0 <num>:
 804c3c0:	00 00                	add    %al,(%eax)
 804c3c2:	38 6c c6 c6          	cmp    %ch,-0x3a(%esi,%eax,8)
 804c3c6:	d6                   	(bad)  
 804c3c7:	d6                   	(bad)  
 804c3c8:	c6 c6 6c             	mov    $0x6c,%dh
 804c3cb:	38 00                	cmp    %al,(%eax)
 804c3cd:	00 00                	add    %al,(%eax)
 804c3cf:	00 00                	add    %al,(%eax)
 804c3d1:	00 18                	add    %bl,(%eax)
 804c3d3:	38 78 18             	cmp    %bh,0x18(%eax)
 804c3d6:	18 18                	sbb    %bl,(%eax)
 804c3d8:	18 18                	sbb    %bl,(%eax)
 804c3da:	18 7e 00             	sbb    %bh,0x0(%esi)
 804c3dd:	00 00                	add    %al,(%eax)
 804c3df:	00 00                	add    %al,(%eax)
 804c3e1:	00 7c c6 06          	add    %bh,0x6(%esi,%eax,8)
 804c3e5:	0c 18                	or     $0x18,%al
 804c3e7:	30 60 c0             	xor    %ah,-0x40(%eax)
 804c3ea:	c6                   	(bad)  
 804c3eb:	fe 00                	incb   (%eax)
 804c3ed:	00 00                	add    %al,(%eax)
 804c3ef:	00 00                	add    %al,(%eax)
 804c3f1:	00 7c c6 06          	add    %bh,0x6(%esi,%eax,8)
 804c3f5:	06                   	push   %es
 804c3f6:	3c 06                	cmp    $0x6,%al
 804c3f8:	06                   	push   %es
 804c3f9:	06                   	push   %es
 804c3fa:	c6                   	(bad)  
 804c3fb:	7c 00                	jl     804c3fd <num+0x3d>
 804c3fd:	00 00                	add    %al,(%eax)
 804c3ff:	00 00                	add    %al,(%eax)
 804c401:	00 0c 1c             	add    %cl,(%esp,%ebx,1)
 804c404:	3c 6c                	cmp    $0x6c,%al
 804c406:	cc                   	int3   
 804c407:	fe 0c 0c             	decb   (%esp,%ecx,1)
 804c40a:	0c 1e                	or     $0x1e,%al
 804c40c:	00 00                	add    %al,(%eax)
 804c40e:	00 00                	add    %al,(%eax)
 804c410:	00 00                	add    %al,(%eax)
 804c412:	fe c0                	inc    %al
 804c414:	c0 c0 fc             	rol    $0xfc,%al
 804c417:	06                   	push   %es
 804c418:	06                   	push   %es
 804c419:	06                   	push   %es
 804c41a:	c6                   	(bad)  
 804c41b:	7c 00                	jl     804c41d <num+0x5d>
 804c41d:	00 00                	add    %al,(%eax)
 804c41f:	00 00                	add    %al,(%eax)
 804c421:	00 38                	add    %bh,(%eax)
 804c423:	60                   	pusha  
 804c424:	c0 c0 fc             	rol    $0xfc,%al
 804c427:	c6 c6 c6             	mov    $0xc6,%dh
 804c42a:	c6                   	(bad)  
 804c42b:	7c 00                	jl     804c42d <num+0x6d>
 804c42d:	00 00                	add    %al,(%eax)
 804c42f:	00 00                	add    %al,(%eax)
 804c431:	00 fe                	add    %bh,%dh
 804c433:	c6 06 06             	movb   $0x6,(%esi)
 804c436:	0c 18                	or     $0x18,%al
 804c438:	30 30                	xor    %dh,(%eax)
 804c43a:	30 30                	xor    %dh,(%eax)
 804c43c:	00 00                	add    %al,(%eax)
 804c43e:	00 00                	add    %al,(%eax)
 804c440:	00 00                	add    %al,(%eax)
 804c442:	7c c6                	jl     804c40a <num+0x4a>
 804c444:	c6 c6 7c             	mov    $0x7c,%dh
 804c447:	c6 c6 c6             	mov    $0xc6,%dh
 804c44a:	c6                   	(bad)  
 804c44b:	7c 00                	jl     804c44d <num+0x8d>
 804c44d:	00 00                	add    %al,(%eax)
 804c44f:	00 00                	add    %al,(%eax)
 804c451:	00 7c c6 c6          	add    %bh,-0x3a(%esi,%eax,8)
 804c455:	c6                   	(bad)  
 804c456:	7e 06                	jle    804c45e <num+0x9e>
 804c458:	06                   	push   %es
 804c459:	06                   	push   %es
 804c45a:	0c 78                	or     $0x78,%al
 804c45c:	00 00                	add    %al,(%eax)
	...

Disassembly of section .bss:

0804c460 <completed.7021>:
 804c460:	00 00                	add    %al,(%eax)
	...

0804c464 <dtor_idx.7023>:
	...

0804c480 <pos_flag>:
	...

0804c804 <buf_mouse>:
	...

0804c820 <player_win_table>:
	...

0804cbc0 <computer_win_table>:
	...

0804cf60 <player_chess>:
	...

0804d300 <computer_chess>:
	...

0804d684 <player_max_x>:
 804d684:	00 00                	add    %al,(%eax)
	...

0804d688 <player_max_y>:
 804d688:	00 00                	add    %al,(%eax)
	...

0804d68c <computer_max_x>:
 804d68c:	00 00                	add    %al,(%eax)
	...

0804d690 <computer_max_y>:
 804d690:	00 00                	add    %al,(%eax)
	...

0804d694 <i>:
 804d694:	00 00                	add    %al,(%eax)
	...

0804d698 <j>:
 804d698:	00 00                	add    %al,(%eax)
	...

0804d69c <k>:
 804d69c:	00 00                	add    %al,(%eax)
	...

0804d6a0 <p>:
 804d6a0:	00 00                	add    %al,(%eax)
	...

0804d6a4 <m>:
 804d6a4:	00 00                	add    %al,(%eax)
	...

0804d6a8 <n>:
 804d6a8:	00 00                	add    %al,(%eax)
	...

0804d6ac <left_score>:
 804d6ac:	00 00                	add    %al,(%eax)
	...

0804d6b0 <right_score>:
 804d6b0:	00 00                	add    %al,(%eax)
	...

0804d6b4 <up_score>:
 804d6b4:	00 00                	add    %al,(%eax)
	...

0804d6b8 <down_score>:
 804d6b8:	00 00                	add    %al,(%eax)
	...

0804d6bc <left_up_score>:
 804d6bc:	00 00                	add    %al,(%eax)
	...

0804d6c0 <right_up_score>:
 804d6c0:	00 00                	add    %al,(%eax)
	...

0804d6c4 <left_down_score>:
 804d6c4:	00 00                	add    %al,(%eax)
	...

0804d6c8 <right_down_score>:
	...

0804d6e0 <player_max>:
 804d6e0:	00 00                	add    %al,(%eax)
	...

0804d6e4 <w>:
 804d6e4:	00 00                	add    %al,(%eax)
	...

0804d6e8 <fbmem>:
 804d6e8:	00 00                	add    %al,(%eax)
	...

0804d6ec <h>:
 804d6ec:	00 00                	add    %al,(%eax)
	...

0804d6f0 <old_cx>:
 804d6f0:	00 00                	add    %al,(%eax)
	...

0804d6f4 <cx>:
 804d6f4:	00 00                	add    %al,(%eax)
	...

0804d6f8 <old_cy>:
 804d6f8:	00 00                	add    %al,(%eax)
	...

0804d6fc <cy>:
 804d6fc:	00 00                	add    %al,(%eax)
	...

0804d700 <computer_max>:
	...

0804d720 <buf>:
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	47                   	inc    %edi
   1:	43                   	inc    %ebx
   2:	43                   	inc    %ebx
   3:	3a 20                	cmp    (%eax),%ah
   5:	28 55 62             	sub    %dl,0x62(%ebp)
   8:	75 6e                	jne    78 <_init-0x80483d4>
   a:	74 75                	je     81 <_init-0x80483cb>
   c:	20 34 2e             	and    %dh,(%esi,%ebp,1)
   f:	34 2e                	xor    $0x2e,%al
  11:	33 2d 34 75 62 75    	xor    0x75627534,%ebp
  17:	6e                   	outsb  %ds:(%esi),(%dx)
  18:	74 75                	je     8f <_init-0x80483bd>
  1a:	35 29 20 34 2e       	xor    $0x2e342029,%eax
  1f:	34 2e                	xor    $0x2e,%al
  21:	33 00                	xor    (%eax),%eax
