***Interrupt Handling:***

Processor need to detect hardware actiivies. There are multiple solutions to detects the hardware activities. For example, Let consider the polling. 
In polling every repeated time, hardware status will get verified without knowing whether device active or ready. It is overhead process to detect the hardware status.
The better solution is that hardware should provide the signal to processor about activities to gain the attention of the processor when it really required. This mechanism is called as interrupt. 

Hardware generates interrupts asynchronously and helps to gain the attention from the CPU to process its handler. 

An interrupt is produced by electronic signals from hardware devices and directed into input pins on an interrupt controller. 
1) After receiving the interrupt, interrupt controller will send a signal to processor.
2) Processor detects the singal and halts the current execution context. 
3) Processor will notify the operating system about the incoming insterrupt to handle further. 
4) Operating system will call the interrupt handler or routies which further resolved the interrupt. 
5) Operating sytem notify back about the Interrupt completion to processor to resume the saved contexts

Different devices are associated with different interrupts. Each interrupts are identified nby unique number or value. This will operating system to distinguish interrupts and call appropirate interrupt handler. These interrupt values are also called as IRQ Lines ( Interrupt Request Lines).

- Each IRQ line is assigned a numeric value. For example, on the classic PC, IRQ zero is the timer interrupt and IRQ one is the keyboard interrupt.
- Some interrupts are dynamically assigned, such as interrupts associated with devices on the PCI bus. Other non-PC architectures have similar dynamic assignments for interrupt values.
- The kernel knows that a specific interrupt is associated with a specific device. The hardware then issues interrupts to get the kernel's attention.

**Kernel handle the interrupt with following sequence of operations**
1) It saves the current register context of the executing process and creates new context layer.
2) It will determine the source or cause of the interrupt, identifying the type of interrupt and unit number of the interrupt.
3) Received interrupt is associated with number and that will be the offset into a table commonly called as "Interrupt Vector".
4) "Interrupt Vector" contains the address of the interrupt handler for the corresponding interrupt number.
5) Then kernel invokes the interrupt handler.
6) Interrupt handler completes the it work and returns. Then kernel restore the privous context and start the execution.

Interrupt handler is also called as "Interrupt Service Routine" (ISR). In Linux, interrupt handlers are normal C functions, which match a specific prototype and thus enables the kernel to pass the handler information in a standard way. What differentiates interrupt handlers from other kernel functions is that the kernel invokes them in response to interrupts and that they run in a special context called interrupt context. This special context is occasionally called atomic context because code executing in this context is unable to block.

**Registration of Interrupt and Handler**

Devices are comes with device driver. If the device  uses the interrupt, then it will get register the interrupt handler. Drivers can register an interrupt handler and enable a given interrupt line for handling with the function request_irq(), which is declared in <linux/interrupt.h>:

Devices are comes with device driver. If the device  uses the interrupt, then it will get register the interrupt handler. Drivers can register an interrupt handler and enable a given interrupt line for handling with the function request_irq(), which is declared in <linux/interrupt.h>

``` C++
int request_irq(unsigned int irq,
                irq_handler_t handler,
                unsigned long flags,
                const char *name,
                void *dev)
 ```
 
 1st Argument: IRQ Number - Interrupt number to allocate.
 2nd Argument: Handler - Function pointer of the handler to be invoked.
 3rd Argument: Flag - Flag helps to identify the activities stage or criteria of interrupts.
        IRQF_DISABLED - this flag instructs the kernel to disable all interrupts when executing this interrupt handler.
        IRQF_SHARED - This flag specifies that the interrupt line can be shared among multiple interrupt handlers. Each handler registered on a given                            line must specify this flag; otherwise, only one handler can exist per line.
