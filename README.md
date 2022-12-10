# First-Principles implementation of probabilistic LDPC error correcting codes on embedded platform in AWGN and Rayleigh fading channels

## Aim
This project aims to develop a probabilistic LDPC encoder that is able to decode messages effectively to come close to the optimal Shannon’s limit for an error-correcting system in the presence of an AWGN channel and implement this error-correcting system on an embedded platform. The project has the secondary goal of being able to accurately decode a real-world audio signal in the presence of a Rayleigh flat-fading channel model.

## Conclusion
In summary, the project involved three main challenges. Firstly, the design and implementation of an optimized encoder that is able to efficiently encode a message based on the 5G-NR base matrix standard. This involves making use of in-place operations in order to cut down on memory usage and run time. Secondly, the design and implementation of an optimized decoder that is able to efficiently decode a message in presence of high noise in the 5G-NR base matrix standard. This involves making use of in-place calculations that cuts down on memory usage and run time. Thirdly, the system must be implemented on an embedded platform such that the system meets the required run-time requirement and also doesn’t run out of memory due to the long codeword lengths used in the system.

## Summary of observations and findings
The system is the first LDPC decoder that I could find in literature that has been applied to decoding messages that were sent over a Rayleigh flat-fading channel and therefore is a benchmark when it comes to the performance of a probabilistic LDPC system in the presence of a Rayleigh flat-fading channel.

The system is able to decode messages in the presence of very high noise and is able to do so in a short run-time on low memory, low processing power embedded device. This is noteworthy since it provides a benchmark for the performance of future projects in the space of LDPC codes on embedded devices.



----------------------------------------------------------------
I achieved a final mark of B+ for the project.


