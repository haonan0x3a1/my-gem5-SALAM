/*
 * Copyright (c) 2015, University of Kaiserslautern
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Matthias Jung
            Frederik Lauer
 */

#include <cstdio>
#include <cstdlib>
#include "vadd.h"

#define SPM
#define LENGTH 512

vadd_struct vas;

int main(void) {
#ifndef SPM
	uint64_t base = 0x80c00000;
#else
    uint64_t base = 0x2f000020;
#endif

    int check[LENGTH];

	void *a = (void *)(base+0);
	void *b = (void *)(base+4*LENGTH);
	void *c = (void *)(base+8*LENGTH);

	common_val = 0;
    vas.a = (int *)a;
    vas.b = (int *)b;
    vas.c = (int *)c;
    vas.check = check;
    vas.length = LENGTH;
    printf("Generating data\n");
    genData(&vas);
    printf("Data generated\n");

    val_a = (uint64_t)base;
    val_b = (uint64_t)(base+4*LENGTH);
    val_c = (uint64_t)(base+8*LENGTH);

    int i;
    printf("%d\n", acc);

    acc = 0x01;
    printf("%d\n", acc);

	while(acc != 0x4) {
        printf("%d\n", acc);
	}
	checkData(&vas);
	for (i = 0; i < LENGTH; i++) {
	    printf("C[%2d]=%d\n", i, vas.c[i]);
	}
}
