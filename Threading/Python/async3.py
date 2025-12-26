import asyncio

async def work1():
    print("A")
    await asyncio.sleep(4)
    print("B")

async def work2():
    print("C")
    await asyncio.sleep(1)
    print("D")

async def main():
    t1 = asyncio.create_task(work1())
    t2 = asyncio.create_task(work2()) 

    await t1
    await t2


asyncio.run(main())