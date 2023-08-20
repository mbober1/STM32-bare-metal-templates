# STM32F411 Bare-Metal Project Templates

#### This repository contains bare-metal project templates for programming the STM32F411 microcontroller in C. These templates are designed for developers who want to work directly with the processor's registers, bypassing the HAL (Hardware Abstraction Layer) libraries. 

#### Through the creation of this repository, I aim to acquire a fundamental understanding of working with STM32 registers. Additionally, I aspire to compile a knowledge compendium, not only for my own benefit but also for others.

## Table of Contents

- [Overview](#overview)
- [Getting Started](#getting-started)
- [Project Templates](#project-templates)
- [Resources](#resources)
- [Contributing](#contributing)

## Overview

This repository offers a set of project templates that provide a starting point for developing bare-metal applications for the STM32F411 microcontroller.

## Getting Started

To get started with these project templates, follow these steps:

1. Clone this repository to your development environment:

   ```shell
   git clone https://github.com/mbober1/STM32-bare-metal-templates.git

2. Open the template that best suits your needs in your favorite IDE or build system.
3. Customize the template for your specific project requirements.
4. Build
   ```shell
   make

5. Flash the project to your STM32F411 development board. In every project folder there is ready to use launch.json script prepared for VSCode + JLink setup.

## Project Templates

This repository provides a set of project templates for the STM32F411 microcontroller, focusing on bare-metal programming without HAL libraries. Each template serves as a starting point for specific tasks or peripherals.

### Clear Template
- **Description**: A minimalistic template offering a clean slate for your projects.

### GPIO Output (General-Purpose Input/Output - Output)
- **Description**: Configures GPIO pins as digital outputs and provides an example.
- **[STM32 Register Level Programming and GPIO](https://hackmd.io/@hrbenitez/158_2s2223_GPIO)**:  - Very detailed tutorial prepared by Herlan Benitez

### GPIO Input (General-Purpose Input/Output - Input)
- **Description**: Configures GPIO pins as digital input with optional external interrupt.
- **[STM32 Register Level Programming and GPIO](https://hackmd.io/@hrbenitez/158_2s2223_GPIO)**:  - Very detailed tutorial prepared by Herlan Benitez

### ADC (Analog-to-Digital Converter)
- **Description**: This template configures and demonstrates the very basic usage of the STM32F411's Analog-to-Digital Converter (ADC).

### ADC DMA (Direct Memory Access)
- **Description**: A variant of the ADC template that utilizes Direct Memory Access (DMA) for efficient data transfer from the ADC to memory.

### TIM Time-Base (Timer - Time-Base)
- **Description**: Configures a timer as a time-base signal source and offers a basic example. Suitable for projects requiring precise timing intervals or periodic interrupts.
- **[General-purpose timer cookbook for STM32 microcontrollers](https://www.st.com/resource/en/application_note/an4776-generalpurpose-timer-cookbook-for-stm32-microcontrollers-stmicroelectronics.pdf)** - ST cookbook for timers, 
- **[STM32 Interrupts and Timers](https://hackmd.io/@hrbenitez/158_2s2223_Int_Tim)** - Very detailed tutorial prepared by Herlan Benitez, 

### TIM Output Mode (Timer - Output Mode)
- **Description**: An extension of the timer template, it configures the timer for generating output signals like PWM (Pulse Width Modulation). Useful for motor control, LED brightness modulation, and signal generation.

### TIM Input Mode (Timer - Input Mode)
- **Description**: Configures the timer as an input and demonstrates measuring the duration or frequency of an external signal. Valuable for applications involving pulse width measurement or event counting.

These templates aim to expedite your STM32F411 development by providing a structured foundation for various use cases. Dive into the template that aligns with your project requirements and build upon it for your specific needs.


## Resources

For comprehensive documentation on the STM32F411CE microcontroller and its peripherals, refer to the following resources:

- [STM32F411CE Reference Manual](https://www.st.com/resource/en/reference_manual/rm0383-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) - The official reference manual provides detailed information about the microcontroller's features, registers, and functionality.

- [Kamami Nucleo KA-NUCLEO-F411CE](https://wiki.kamamilabs.com/images/8/83/KA-NUCLEO-F411v2_schemat_p1.png) - Schematic of the used board.

- [Errata Sheets](https://www.st.com/en/development-tools/stm32cubemx.html) - summary and a description of the device errata.



## Contributing
Contributions to this repository are welcome! If you have improvements, bug fixes, or additional project templates that you'd like to contribute, please follow the standard GitHub fork and pull request workflow.
