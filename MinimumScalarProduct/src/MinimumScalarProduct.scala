import scala.io.StdIn

/**
  * Created by busungkim on 2017. 2. 23..
  */
object MinimumScalarProduct {

  def main(args: Array[String]): Unit = {
    val T = StdIn.readInt()

    def test(t: Int) = {
      val n = StdIn.readInt

      val numList1 = StdIn.readLine.split(' ').map(_.toLong).toList.sorted
      val numList2 = StdIn.readLine.split(' ').map(_.toLong).toList.sorted.reverse

      assert(numList1.length == n && numList2.length == n)

      val s = numList1.zip(numList2).map(e => e._1 * e._2).sum
      printf("Case #%d: %d\n", t, s)
    }

    for(t <- 1 to T) test(t)
  }
}
