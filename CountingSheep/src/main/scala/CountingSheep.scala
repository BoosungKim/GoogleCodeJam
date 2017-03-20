package main.scala

import scala.io.StdIn

/**
  * Created by busungkim on 2017. 3. 20..
  */
object CountingSheep {
  def main(args: Array[String]): Unit = {

    def solve(tc: Int): Unit = {

      def check(n: Int, mp:Int, set: Set[Int]): Int = {
        val num = n * mp
        val newSet = set diff num.toString.groupBy(c => c).map(c => c._1 - '0').toSet

//        println("Set: ", set)
//        println("Cur: ", cur)
//        println("New set: ", newSet)

        if(mp > 100) -1
        else if(newSet.isEmpty) num
        else check(n, mp+1, newSet)
      }

      val n = StdIn.readInt
      val res = check(n, 1, (0 to 9).toSet)
      printf("Case #%d: ", tc)
      if(res == -1) printf("INSOMNIA\n") else printf("%d\n", res)
    }

    for(tc <- 1 to StdIn.readInt) solve(tc)
  }
}
