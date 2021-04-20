
import java.util.*;
import java.io.*;

class KNearestPoint{
    class Point{
        int x;
        int y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    
    class PointComparator implements Comparator<Point>{
		private double dist(int x, int y){
			return Math.pow(x, 2) + Math.pow(y,2);
		}
		 
		public int compare(Point p1, Point p2){
			double dist1 = dist(p1.x, p1.y);
			double dist2 = dist(p2.x, p2.y);
			return dist1 < dist2 ? -1: ((dist1==dist2)?0:1);
		}
	}
    
    public Point[] findKNearestPoint(int[][] points, int k){
		PriorityQueue<Point> pq = new PriorityQueue<Point>(k, new PointComparator());
		Point[] result = new Point[k];
		for(int[] point : points){
			
			pq.add(new Point(point[0], point[1]));
		}
		
		for(int i=0; i<k&&!pq.isEmpty(); i++){
			result[i] = pq.poll();
		}
		
		return result;
	}
	
	public static void printArr(Point[] points){
		for(Point p : points){
			System.out.print("("+ p.x + ", " + p.y + "), ");
		}
	}

    public static void main(String[] args){
        int[][] points = {{0, 0}, {1, 2}, {-3, 4}, {3, 1}};
        int k = 2;
        KNearestPoint kn = new KNearestPoint();
        Point[] nearestPoints = kn.findKNearestPoint(points, k);
        printArr(nearestPoints);
    }
}
