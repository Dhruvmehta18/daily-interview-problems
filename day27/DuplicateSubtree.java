package day27;

import java.util.ArrayList;
import java.util.HashMap;

public class DuplicateSubtree {

	static class Node {
		int value;
		Node left;
		Node right;

		Node(int value) {
			this.value = value;
		}

		Node(int value, Node left, Node right) {
			this.value = value;
			this.left = left;
			this.right = right;
		}
	}

	private static String inOrderHelper(Node root, HashMap<String, ArrayList<Node>> map) {
		if (root == null) {
			return "";
		}

		String inorderStr = "(";
		inorderStr += inOrderHelper(root.left, map);
		inorderStr += root.value;
		inorderStr += inOrderHelper(root.right, map);

		if (map.containsKey(inorderStr)) {
			map.get(inorderStr).add(root);
			map.put(inorderStr, map.get(inorderStr));
		} else {
			ArrayList<Node> nodes = new ArrayList<Node>();
			nodes.add(root);
			map.put(inorderStr, nodes);
		}

		return inorderStr;
	}

	private static HashMap<String, ArrayList<Node>> inorder(Node root) {
		HashMap<String, ArrayList<Node>> map = new HashMap<String, ArrayList<Node>>();

		inOrderHelper(root, map);

		return map;
	}

	private static ArrayList<ArrayList<Node>> dupTreesHelper(Node root) {
		HashMap<String, ArrayList<Node>> map = inorder(root);
		ArrayList<ArrayList<Node>> result = new ArrayList<ArrayList<Node>>();
		for (ArrayList<Node> list : map.values()) {
			if (list.size() > 1) {
				result.add(list);
			}
		}

		return result;
	}

	public static ArrayList<ArrayList<Node>> dupTrees(Node root) {
		if (root == null || root.left == null || root.right == null) {
			return new ArrayList<>();
		}
		return dupTreesHelper(root);
	}

	private static void postorder(Node p)
	{
		if(p != null) {
			if(p.left != null) postorder(p.left);
			if(p.right != null) postorder(p.right);
			System.out.print(p.value + " ");
		}
	}

	public static void printPostOrderList(ArrayList<Node> list){
		for (Node node : list){
			postorder(node);
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Node n3_1 = new Node(3);
		Node n2_1 = new Node(2, n3_1, null);
		Node n3_2 = new Node(3);
		Node n2_2 = new Node(2, n3_2, null);
		Node n1 = new Node(1, n2_1, n2_2);

		ArrayList<ArrayList<Node>> lists = dupTrees(n1);

		for (ArrayList<Node> list : lists) {
			printPostOrderList(list);
		}
	}
}
