package main.scala

import scala.io.StdIn

/**
  * Created by busungkim on 2017. 3. 13..
  */
object FileFixIt {
  def main(args: Array[String]): Unit = {
    val numTestCase = StdIn.readInt

    def solve(tc: Int) = {
      val nm = StdIn.readLine.split(" ").map(_.toInt)
      val N = nm(0)
      val M = nm(1)

      def inputPath(i: Int, ub: Int): List[String] = if(i == ub) Nil else StdIn.readLine +: inputPath(i+1, ub)

      val existingPaths = inputPath(0, N)
      val newPaths = inputPath(0, M)

      def makeDictAddingPath(path: String, currentDict: Set[String]): Set[String] = {
        if(currentDict contains path) currentDict
        else makeDictAddingPath(path.take(path.lastIndexOf("/")), currentDict) + path
      }

      val foldFunc = (dict: Set[String], path: String) => makeDictAddingPath(path, dict)
      val existingDict = existingPaths.foldLeft(Set(""))(foldFunc)
      val completeDict = newPaths.foldLeft(existingDict)(foldFunc)

      printf("Case #%d: %d\n", tc, completeDict.size - existingDict.size)
    }

    for(tc <- 1 to numTestCase) solve(tc)
  }
}