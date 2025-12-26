import asyncio

async def work1():
    print("A")
    await asyncio.sleep(3)
    print("B")

async def work2():
    print("C")
    await asyncio.sleep(1)
    print("D")


async def main():
    await asyncio.gather
    ( work1(),work2())


asyncio.run(main())