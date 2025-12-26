import asyncio


async def work():
    print("A")
    await asyncio.sleep(5)
    print("B")

async def work2():
    print("C")
    await asyncio.sleep(1)
    print("D")

asyncio.run(work())
asyncio.run(work2())

